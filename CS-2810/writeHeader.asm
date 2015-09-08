; writeHeader(buffer, x, y) -> # bytes written
; writes a .ppm file header to the buffer, and returns the
; number of bytes written. The maximum color value is hard-coded
; at 255, but the x and y sizes can be any non-negative integers.
;
; example: writeHeader(buffer, 100, 50) writes
; "P3\n100 50\n255\n" to the buffer and returns 14.

global writeHeader
extern itoa

sys_write:      equ 1
; sys_exit:       equ 60
stdout:         equ 1
newline:        equ 10

section .data
colormax:       dq 255

section .text

; writeHeader(buffer, x, y) -> # bytes written
writeHeader:
                ; save old values by pushing to the stack
                push r12
                push r13
                push r14
                push r15

                ; move parameters to safe registers
                mov r12, 0   ; total buffer length
                mov r13, rdi ; buffer
                mov r14, rsi ; xsize
                mov r15, rdx ; ysize

                ; Hard Code P3
                mov al, 'P'
                mov [r13 + r12], al
                inc r12
                mov al, '3'
                mov [r13 + r12], al
                inc r12

                ; append a newline
                mov al, newline
                mov [r13 + r12], al
                inc r12

                ; Call itoa # r12 += itoa(buffer + length, xsize)
                mov rdi, [r13 + r12]
                mov rsi, r14
                call itoa
                add r12, rax

                ; Add space between xsize, ysize
                mov al, ' '
                mov [r13 + r12], al
                inc r12

                ; Call itoa # r12 += itoa(buffer + length, ysize)
                mov rdi, [r13 + r12]
                mov rsi, r15
                call itoa
                add r12, rax

                ; append a newline
                mov al, newline
                mov [r13 + r12], al
                inc r12

                ; Hard Code 255
                ; Call itoa # r12 += itoa(buffer + length, colormax)
                mov rdi, [r13 + r12]
                mov rsi, [colormax]
                call itoa
                add r12, rax

                ; append a newline
                mov al, newline
                mov [r13 + r12], al
                inc r12

                ; return buffer length
                mov rax, r12

                ; pop old values off the stack
                pop r15
                pop r14
                pop r13
                pop r12

