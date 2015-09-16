
global _start
extern writearray

sys_write:     equ 1
sys_exit:      equ 60
stdout:        equ 1

section .data
values: 		dq 345, 342, 67, 45, 21, 98, 34, 1, 7776, 23, 67
length:			equ ($-array)/8


section .bss
out:			resb 1000


section .text
_start:
				; writearray(buffer, array, length) -> # bytes written
				mov rdi, out
				mov rsi, array
				mov rdx, length
				call writearray

				; write(stdout, buffer, len)
               	mov rdi, stdout
               	mov rsi, out
               	mov rdx, rax
               	mov rax, sys_write
               	syscall

               	; check for error
               	cmp rax, 0
               	jge .okay

check:
               	; exit(1)
               	mov rdi, 1
               	mov rax, sys_exit
               	syscall


.okay:
				mov rdi, 0
				mov rax, sys_exit
				syscall


				