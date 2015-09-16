;global _start
global start
extern writeRGB
extern writeHeader

sys_write:      equ 1
sys_exit:       equ 60
sys_open        equ 2
sys_close       equ 3
stdout:         equ 1

flags:			equ 577
mode:			equ	0o644

xsize:          equ 256
ysize:		    equ 256

newline:        equ 10

section .data
filename: 		db "gradient.ppm", 0

section .bss
buffer:			resb 20000

section .text

; _start:
;                 call start
;                 mov rdi, rax
;                 mov rax, sys_exit
;                 syscall
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
               	ret
               	
.open_okay:
				; Call writeHeader # r8 = itoa(buffer, xsize, ysize)
                mov rdi, buffer
                mov rsi, xsize
                mov rdx, ysize
                call writeHeader
                mov r12, rax

                ; sys_write(fd, buffer, count) -> # bytes or - for error
                mov rdi, r12
                mov rsi, buffer
                mov rdx, r12
                mov rax, sys_write
               	syscall

                ; if status < 0: return 2 (error)
               	cmp rax, 0
               	jge .outer_loop
               	mov rax, 2
               	ret
               	
.outer_loop:
                ; if row > 255: goto .end_outer
				cmp r14, 256
				jge .end_outer
                mov r12, 0 ; bufsize = 0
.inner_loop:
				; if column > 255: goto .end_inner
				cmp r15, 256
				jge .end_inner

                ; color = row << 16 + column << 8
                mov ax, '0'
                mov al, '0'

                ; bufsize += writeRGB(buffer + bufsize, color)
                lea rdi, [buffer + r12]
                mov rsi, rax
                call writeRGB
                add r12, rax

                ; buffer[bufsize] = ' '
                mov [buffer + r12], byte ' '

                ; bufsize++
                inc r12

                ; inner loop
				jmp .inner_loop

.end_inner:
                ; buffer[bufsize-1] = '\n' // replace last space with a newline
				mov [buffer + r12 - 1], byte newline

                ; status = write(fd, buffer, bufsize)
                mov rdi, r13
                mov rsi, buffer
                mov rdx, r12
                mov rax, sys_write
               	syscall

                ; if status < 0: return 3 (error)
               	cmp rax, 0
               	jge .outer_loop
               	mov rax, 3
               	ret
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
               	ret
               	
.success:
				; return exit code 0 = success
                mov rax, 0

                ; sys_exit(status)
                ; mov rdi, 0
				; mov rax, sys_exit
				; syscall

                pop r15
                pop r14
				pop r13
				pop r12

                ret
