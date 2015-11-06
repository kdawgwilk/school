global calcPixel
extern mandel
extern getColor
extern blendColors
extern subpixelOffsets

section .bss
buffer:			resq 4096

section .text
calcPixel:								; calcPixel(maxiters, column, row, xsize, ysize, antialias, xcenter, ycenter, magnification)
                push r12
                push r13
                push r14
                push r15
                push rbx
                
                push rbp					; setup stack frame
				mov rbp, rsp				; copy stack pointer

                push rdi 					; maxiters 						[-8]
                push r9						; antialias 					[-16]
				sub rsp, 8
				movsd [rsp], xmm0			; xcenter 						[-24]
				sub rsp, 8
				movsd [rsp], xmm1			; ycenter 						[-32]
											; denominator					[-40]
                							; numx = (column - xsize / 2) 	[-48]
                							; numy = (row - ysize / 2) 		[-56]

                mov r12, rcx 				; r12 = xsize
                mov r13, r8 				; r13 = ysize
                mov r14, 0 					; r14 = y_index = 0
                mov r15, 0					; r15 = x_index = 0
                mov rbx, 0	 				; rbx = total_colors = 0
                							; xmm0 = xcenter
                							; xmm1 = ycenter
                							; xmm2 = magnification

               	mov r8, r12  				; minsize = xsize
               	cmp r8, r13  				; if xsize <= ysize
               	jle .continue 					; goto .continue
               	mov r8, r13  				; minsize = ysize
.continue:
				sub r8, 1 					; minsize = minsize - 1
				cvtsi2sd xmm3, r8
				mulsd xmm2, xmm3			; denominator = magnification * minsize

				sub rsp, 8
				movsd [rsp], xmm2			; denominator 					[-40]

				shr r12, 1 					; halfxsize = (xsize / 2)
				sub rsi, r12				; numx = column - halfxsize
				cvtsi2sd xmm3, rsi
				sub rsp, 8
				movsd [rsp], xmm3			; numx 							[-48]

				shr r13, 1					; halfysize = (ysize / 2)
				sub rdx, r13				; numy = row - halfysize
				cvtsi2sd xmm3, rdx
				sub rsp, 8
				movsd [rsp], xmm3			; numy 							[-56]
.outer_loop:								; while
				cmp r14, [rbp - 16]				; if y_index >= antialias
				jge .end_outer						; goto .end_outer
				mov r15, 0
.inner_loop:									; while
				cmp r15, [rbp - 16]					; if x_index >= antialias
				jge .end_inner							; goto .end_inner

				movsd xmm3, [rbp - 48]				; xmm3 = numx
				addsd xmm3, [subpixelOffsets + r15 * 8] ; colx = numx + subpixelOffsets[x_index]
				divsd xmm3, [rbp - 40]				; divx = colx / denominator
				movsd xmm0, [rbp - 24]				; xmm0 = xcenter
				addsd xmm0, xmm3					; x = xcenter + divx

				movsd xmm3, [rbp - 56]				; xmm3 = numy
				addsd xmm3, [subpixelOffsets + r14 * 8] ; coly = numy + subpixelOffsets[y_index]	
				divsd xmm3, [rbp - 40]				; divy = coly / denominator
				movsd xmm1, [rbp - 32]				; xmm1 = ycenter
				subsd xmm1, xmm3					; y = ycenter - divy

				mov rdi, [rbp - 8]					; rdi = maxiters
				call mandel							; iters = mandel(maxiters, x, y)
				mov rdi, rax
				call getColor						; color = getColor(iters)
				mov [buffer + rbx * 8], rax				; buffer[total_colors] = color
				inc rbx								; total_colors++
				inc r15								; x_index++
				jmp .inner_loop						; goto .inner_loop
.end_inner:										; endwhile
				inc r14							; y_index++
				jmp .outer_loop					; goto .outer_loop
.end_outer:									; endwhile
				mov rdi, buffer
				mov rsi, rbx
				call blendColors			; rgb_color = blendColors(buffer, total_colors)
.return:									; return rgb_color
				mov rsp, rbp				; reset stack pointer
                pop rbp						; delete stack frame

                pop rbx
                pop r15
				pop r14
				pop r13
				pop r12
				ret


