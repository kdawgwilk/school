; writeHeader(buffer, x, y) -> # bytes written
; writes a .ppm file header to the buffer, and returns the
; number of bytes written. The maximum color value is hard-coded
; at 255, but the x and y sizes can be any non-negative integers.
;
; example: writeHeader(buffer, 100, 50) writes
; "P3\n100 50\n255\n" to the buffer and returns 14.

global _start
extern itoa

sys_write:     equ 1
sys_exit:      equ 60
stdout:        equ 1
newline:       equ 10

section .data
n:             dq 324987349

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

               ; gdb a.out (debugger)

               ;run (to run debugger)
               ;print $r8 (gives value in register)
               ;x 9 (examine address)
               ;b _start (breakpoint at _start)
               ;run steps through
               ;l ()

