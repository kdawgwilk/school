global start
extern writeRGB
extern writeHeader
extern calcPixel

sys_write:      equ 1
sys_exit:       equ 60
sys_open        equ 2
sys_close       equ 3
stdout:         equ 1

flags:          equ 577
mode:           equ 0o644

newline:        equ 10
space:          equ 32

xsize:          equ 256
ysize:          equ 256

section .data
filename:       db "fractal.ppm", 0
iters:          dq 255

section .bss
buffer:         resb 1024 * 20

section .text

start:
                ; push any previously stored values to stack
                push r12 ; count
                push r13 ; fd // filedescriptor
                push r14 ; row
                push r15 ; column
                
                mov r12, 0 ; buffer_length = 0
                mov r14, 0 ; row = 0
                mov r15, 0 ; column = 0
        
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
                mov rsi, xsize
                mov rdx, ysize
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
                ; if row > 255: goto .end_outer
                cmp r14, xsize
                jge .end_outer
                mov r12, 0 ; = xor r12, r12 // bufsize = 0
                mov r15, 0 ; column = 0
.inner_loop:
                ; if column > 255: goto .end_inner
                cmp r15, ysize
                jge .end_inner

                ; color = row << 16 + column << 8
                ; mov rax, r14
                ; shl rax, 16 ; shift left 16 bits
                ; mov rdx, r15
                ; shl rdx, 8 ; shift left 8 bits
                ; add rax, rdx

                ; calcPixel(maxiters, col, row) -> rgb
                mov rdi, [iters]
                mov rsi, r15
                mov rdx, r14
                call calcPixel

                ; bufsize += writeRGB(buffer + bufsize, color)
                lea rdi, [buffer + r12]
                mov rsi, rax
                call writeRGB
                add r12, rax

                ; buffer[bufsize] = ' '
                mov [buffer + r12], byte space
                inc r12 ; bufsize++

                inc r15 ; column++
                ; inner loop
                jmp .inner_loop

.end_inner:
                ; buffer[bufsize - 1] = '\n' // replace last space with a newline
                mov [buffer + r12 - 1], byte newline

                inc r14 ; row++

                ; status = write(fd, buffer, bufsize)
                mov rdi, r13
                mov rsi, buffer
                mov rdx, r12
                mov rax, sys_write
                syscall


                ; if status < 0: return 3 (error)
                cmp rax, 0
                jmp .outer_loop

                ; sys_exit(status)
                ; mov rdi, rax
                ; mov rax, sys_exit
                ; syscall

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

