; itoa: convert a non-negative integer to ascii (text)
; itoa(buffer, n) -> # bytes written

global itoa

section .text

; itoa(buffer, n) -> # bytes written
itoa:
        mov rax, rsi            ; copy n into rax
        mov rsi, 0              ; rsi = length of output
        mov r10, 10             ; to help divide by 10

.loop:
        ; do a division
        mov rdx, 0
        div r10
        add rdx, '0'
        mov [rdi + rsi], dl
        inc rsi
        cmp rax, 0
        jg .loop

        ; reverse the string
        mov rdx, rdi
        lea rcx, [rdi + rsi - 1]
        jmp .reversetest

.reverseloop:
        mov al, [rdx]
        mov ah, [rcx]
        mov [rcx], al
        mov [rdx], ah
        inc rdx
        dec rcx

.reversetest:
        cmp rdx, rcx
        jl .reverseloop

        mov rax, rsi
        ret

