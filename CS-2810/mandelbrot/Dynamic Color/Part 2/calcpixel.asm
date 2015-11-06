global calcPixel
extern mandel
extern getColor

calcPixel:
                ; calcPixel(maxiters, column, row, xsize, ysize, xcenter, ycenter, magnification) -> rgb

                push r12
                push r13
                push r14
                push rbx
                push rbp

                mov r12, rdi 	; r12 = maxiters
                mov r13, rsi 	; r13 = col
                mov r14, rdx 	; r14 = row
                mov rbx, rcx 	; rbx = xsize
                mov rbp, r8  	; rbp = ysize
                				; xmm0 = xcenter
                				; xmm1 = ycenter
                				; xmm2 = magnification
                				; xmm3 = minsize
                				; xmm2 = D

               	; minsize = min(xsize, ysize)
               	mov r8, rbx  ; minsize = xsize
               	cmp rbx, rbp  ; if xsize <= ysize
               	jle .continue ; goto continue

               	mov r8, rbp  ; minsize = ysize
.continue:
				; xmm2 = D = (magnification * (minsize - 1))
				sub r8, 1 ; minsize - 1
				cvtsi2sd xmm3, r8
				mulsd xmm2, xmm3

				; rdi = halfxsize = xsize / 2
				mov rax, rbx 	; rax = xsize
				mov rdx, 0
				mov r9, 2
				div r9			; rax = rax / 2
				mov r9, rax		; rdi = rax

				; rax = colx = (column - halfxsize)
				mov r8, r13		; r8 = col
				sub r8, r9		; r8 = r8 - rdi

				; rsi = halfysize = ysize / 2
				mov rax, rbp	; rax = ysize
				mov rdx, 0
				mov r9, 2
				div r9			; rax = rax / 2
				mov r9, rax	; rsi = rax

				; rdx = rowy = (row - halfysize)
				mov rdx, r14	; rdx = row
				sub rdx, r9	; rdx - rsi

    			; x = xcenter + colx / D
				cvtsi2sd xmm3, r8
				divsd xmm3, xmm2
				addsd xmm0, xmm3

				; y = ycenter - rowy / D
				cvtsi2sd xmm4, rdx
				divsd xmm4, xmm2
				subsd xmm1, xmm4

.break:			; x = xmm0, y = xmm1
			    ; calcPixel(1000, 		394, 	193, 407, 	405, 	-0.743643135, 	0.131825963, 40786.41);
                ; calcPixel(maxiters, 	column, row, xsize, ysize, 	xcenter, 		ycenter, 	 magnification) -> rgb

				; x = xcenter + (column - xsize/2) / (magnification * (minsize - 1))
				; x = -0.743643135 + (394 - 407 / 2) / (40786.41 * (405 - 1))

				; y = ycenter - (row - ysize/2) / (magnification * (minsize - 1))
				; y = 0.131825963 - (193 - 405 / 2) / (40786.41 * (405 - 1))

				; mandel(int maxIterations, float x, float y) -> iterations
				mov rdi, r12
				call mandel

				; getColor(iters) -> rgb
				mov rdi, rax
				call getColor

.return:

                pop rbp
                pop rbx
				pop r14
				pop r13
				pop r12

				ret
