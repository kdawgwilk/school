; getColor(iters) -> rgb
global getColor

section .text

getColor:
    ; make sure the input is < 256
    and rdi, 0xff

    ; use rdi as all three color channels
    mov rax, rdi
    shl rax, 8
    or rax, rdi
    shl rax, 8
    or rax, rdi
    ret
