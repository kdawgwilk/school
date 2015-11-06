global start
extern writeRGB
extern writeHeader
extern calcPixel

extern filename
extern iters
extern xsize
extern ysize
extern xcenter
extern ycenter
extern mag
extern antialias

sys_write:      equ 1
sys_exit:       equ 60
sys_open        equ 2
sys_close       equ 3
stdout:         equ 1

flags:          equ 577
mode:           equ 0o644

newline:        equ 10
space:          equ 32

section .bss
buffer:         resb 1024 * 40

section .text

start:
                ; push any previously stored values to stack
                push r12                                ; count
                push r13                                ; fd // filedescriptor
                push r14                                ; row
                push r15                                ; column
                
                mov r12, 0                              ; buffer_length = 0
                mov r14, 0                              ; row = 0
                mov r15, 0                              ; column = 0
        
                ; sys_open(filename, flags, mode) -> file descriptor or - for error
                mov rdi, filename
                mov rsi, flags
                mov rdx, mode
                mov rax, sys_open
                syscall

                mov r13, rax ; save fd

                ; check for error
                cmp rax, 0
                jge .open_okay
                
                ; start returns exit code
                mov rax, 1
                jmp .return
.open_okay:
                ; Call writeHeader # r8 = itoa(buffer, xsize, ysize)
                mov rdi, buffer
                mov rsi, [xsize]
                mov rdx, [ysize]
                call writeHeader
                mov r12, rax

                ; sys_write(fd, buffer, count) -> # bytes or - for error
                mov rdi, r13
                mov rsi, buffer
                mov rdx, r12
                mov rax, sys_write
                syscall

                ; if status < 0: return 2 (error)
                cmp rax, 0
                jge .outer_loop
                mov rax, 2
                jmp .return
.outer_loop:
                ; if row > xsize: goto .end_outer
                cmp r14, [ysize]
                jge .end_outer
                mov r12, 0                              ; = xor r12, r12 // bufsize = 0
                mov r15, 0                              ; column = 0
.inner_loop:
                ; if column > ysize: goto .end_inner
                cmp r15, [xsize]
                jge .end_inner

                ; calcPixel(maxiters, column, row, xsize, ysize, xcenter, ycenter, magnification) -> rgb
                mov rdi, [iters]                        ; maxiters = 1000
                mov rsi, r15                            ; column
                mov rdx, r14                            ; row
                mov rcx, [xsize]                        ; xsize = 128
                mov r8, [ysize]                         ; ysize = 200
                movsd xmm0, [xcenter]                   ; xcenter = -0.743643135
                movsd xmm1, [ycenter]                   ; ycenter = 0.131825963
                movsd xmm2, [mag]                       ; mag = 91152.0
.break:
                call calcPixel

                ; bufsize += writeRGB(buffer + bufsize, color)
                lea rdi, [buffer + r12]
                mov rsi, rax
                call writeRGB
                add r12, rax

                mov [buffer + r12], byte space          ; buffer[bufsize] = ' '
                inc r12                                 ; bufsize++
                inc r15                                 ; column++
                jmp .inner_loop
.end_inner:
                ; buffer[bufsize - 1] = '\n' // replace last space with a newline
                mov [buffer + r12 - 1], byte newline
                inc r14                                 ; row++

                ; status = write(fd, buffer, bufsize)
                mov rdi, r13
                mov rsi, buffer
                mov rdx, r12
                mov rax, sys_write
                syscall

                ; if status < 0: return 3 (error)
                cmp rax, 0
                jmp .outer_loop

                mov rax, 3
                jmp .return
.end_outer:
                ; sys_close(fd) -> - for error
                ; status = close(fd)
                mov rdi, r13
                mov rax, sys_close
                syscall

                ; if status < 0: return 4 (error)
                cmp rax, 0
                jge .success
                mov rax, 4
                jmp .return
.success:
                ; return exit code 0 = success
                mov rax, 0
.return:
                pop r15
                pop r14
                pop r13
                pop r12
                ret

