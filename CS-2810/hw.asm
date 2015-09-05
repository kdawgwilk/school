
; Use NASM and NOT GAS

; global _start

; stdout: equ 1

; section .text
; _start:
; 	mov %rdi, stdout
; 	mov %rsi, hw
; 	mov %rdx, hw_len

; 	mov %rax, 1					; 1 = write system call
; 	syscall

; 	mov %rdi, 0					; exit status 0 (success)
; 	mov %rax, 60					; 60 = exit system call



; section .data
; 	hw:     db "Hello world!", 10
; 	hw_len: equ $-hw


global _start

sys_exit: equ 60

section .text
_start:
	mov rax, 1

	; test if the loop is finished
.test:
	cmp rax, 100
	jge .finished

	; double n
	mov rdi, rax
	call double

	; continue the loop
	jmp .test

.finished:
	;exit
	mov rdi, rax
	mov rax, sys_exit
	syscall

double:
	mov rax, rdi
	add rax, rdi
	ret










	