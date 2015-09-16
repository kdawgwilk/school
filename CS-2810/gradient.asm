;global _start
global start
extern writeRGB
extern writeHeader

flags:			equ 577
mode:			equ	0o644


section .data
filename: 		db "gradient.ppm", 0

section .bss
buffer:			resb 20000

section .text

; _start:
;             call start
;             mov rdi, rax
;             mov rax, sys_exit
            ; syscall
start:
			