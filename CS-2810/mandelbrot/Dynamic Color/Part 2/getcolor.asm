; getColor(iters) -> rgb
global getColor

extern palette
extern palette_size

section .text
getColor:
			; check for 0 iterations
    		mov rax, 0
    		cmp rdi, 0
    		je .return

    		; colorIndex = (iterations - 1) % palette_size
    		mov rax, rdi
    		sub rax, 1
    		mov rdx, 0
    		mov r8, [palette_size]
    		div r8
    		mov rax, [palette + rdx * 8]
.return:
    		ret
