global calcPixel
extern mandel
extern getColor

size:			equ 255
half_size:		equ 128
zoom:			equ 4

calcPixel:
                ; calcPixel(maxiters, col, row) -> rgb
                push r12
                push r13
                push r14

                mov r12, rdi ; r12 = maxiters
                mov r13, rsi ; r13 = col
                mov r14, rdx ; r14 = row

    			; x = (column - 128) / (255.0 / 4.0)
    			; (255.0 / 4.0) Denominator
    			mov rax, size
    			cvtsi2sd xmm2, rax
    			mov rax, zoom
    			cvtsi2sd xmm3, rax
    			divsd xmm2, xmm3

    			; (column - 128)
    			mov rax, r13
				sub rax, half_size
				cvtsi2sd xmm3, rax

				movsd xmm0, xmm3
				divsd xmm0, xmm2

				; y = -(row - 128) / (255.0 / 4.0)
    			; -(row - 128)
    			mov rax, r14
				sub rax, half_size
				neg rax
				cvtsi2sd xmm3, rax

				movsd xmm1, xmm3
				divsd xmm1, xmm2

				; mandel(int maxIterations, float x, float y) -> iterations
				mov rdi, r12
				call mandel

				; getColor(iters) -> rgb
				mov rdi, rax
				call getColor

.return:
				pop r14
				pop r13
				pop r12

				ret



