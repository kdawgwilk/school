; callWriteHeader.asm

global _start
extern writeHeader

sys_write:     equ 1
sys_exit:      equ 60
stdout:        equ 1
newline:       equ 10

section .data
xsize:         dq 100
ysize:		   dq 100

section .bss
buffer:        resb 100

section .text
_start:
               ; Call itoa # r8 = itoa(buffer, n)
               mov rdi, buffer
               mov rsi, [n]
               call itoa
               mov r8, rax

               ; append a newline
               mov al, newline
               mov [buffer + r8], al
               inc r8

               ; wrtite(stdout, buffer, len)
               mov rdi, stdout
               mov rsi, buffer
               mov rdx, r8
               mov rax, sys_write
               syscall

               ; exit(bytes)
               mov rdi, r8 ; still ok after syscall
               mov rax, sys_exit
               syscall


