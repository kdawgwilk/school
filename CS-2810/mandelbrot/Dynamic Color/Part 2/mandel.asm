global mandel

constant:		equ 4

section .text
mandel:
				; mandel(int maxIterations, float x, float y) -> iterations
				push r12 ; iterations
				; set rax (number of iterations) to 1
				mov r12, 1 ; iterations = 1

				; load 4.0 into xmm7
				mov rax, constant
				cvtsi2sd xmm7, rax ; convert the integer in rax to a double in xmm7

				; copy x into a, and y into b
				movsd xmm2, xmm0
				movsd xmm3, xmm1
.loop:
				; compute a², b², and a² + b²
				; a² = a * a
				movsd xmm4, xmm2
				mulsd xmm4, xmm4
				; b² = b * b
				movsd xmm5, xmm3
				mulsd xmm5, xmm5
				; a² + b²
				movsd xmm6, xmm4
				addsd xmm6, xmm5

				; if a² + b² ≥ 4.0, return iterations
				comisd xmm6, xmm7
				jae .end_loop

				; increment iteration count
				inc r12

				; if iterations > maxIterations, return 0
				cmp r12, rdi
				mov rax, 0
				jg .return

				; compute b = 2ab + y (this can be computed in-place, overwriting the old value of b)
				mulsd xmm3, xmm2 ; b *= a
				mov rax, 2
				cvtsi2sd xmm8, rax
				mulsd xmm3, xmm8 ; b *= 2
				addsd xmm3, xmm1 ; b += y

				; compute a = a² - b² + x (this can be computed in-place, overwriting the old value of a; note that a² and b² are already computed)
				movsd xmm2, xmm4 ; a = a²
				subsd xmm2, xmm5 ; a -= b²
				addsd xmm2, xmm0 ; a += x

				jmp .loop
.end_loop:
				; return # of iterations
				mov rax, r12
.return:

				pop r12

				ret
