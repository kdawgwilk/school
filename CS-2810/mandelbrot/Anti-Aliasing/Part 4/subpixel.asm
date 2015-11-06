
global setupSubpixel
global subpixelOffsets

section .data
subpixelOffsets:
				TIMES 64 dq 0 ; store 64 quad words (64 bits each, note that 64-bit floats are okay here)
half:			dq 0.5
section .text
setupSubpixel: 							; setupSubpixel(antialias)
				push r12					; index

				mov r12, 0					; index = 0
.loop:										; while // for i in range(antialias)
				cmp r12, rdi					; if index < antialias
				jge .end_loop						; goto .end_loop

				cvtsi2sd xmm0, r12
				addsd xmm0, [half]				; x = index + 0.5
				cvtsi2sd xmm1, rdi
				divsd xmm0, xmm1				; x = x / antialias
				subsd xmm0, [half]				; x = x - 0.5
				movsd [subpixelOffsets + r12 * 8], xmm0
				
				inc r12							; index++
				jmp .loop						; goto .loop
.end_loop:									; endwhile
				mov rax, 0
				pop r12
				ret
