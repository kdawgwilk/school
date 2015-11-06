global calcPixel
extern mandel
extern getColor
extern blendColors
extern subpixelOffsets

section .bss
buffer:			resb 4096

section .text
calcPixel:							   ; rgb = calcPixel(maxiters, column, row, xsize, ysize, antialias, xcenter, ycenter, magnification)
                push r12
                push r13
                push r14
                push r15
                push rbx
                push rbp

				mov rbp, rsp				; copy stack pointer

                push rdi 					; maxiters 	[-8]
                push rsi					; col 		[-16]
                push rdx					; row 		[-24]
                push r9						; antialias [-32]

                mov r12, rcx 				; r12 = xsize
                mov r13, r8 				; r13 = ysize
                mov r14, 0 					; r14 = y_index
                mov r15, 0					; r15 = x_index
                mov rbx, 0	 				; rbx = total_colors
                							; xmm0 = xcenter
                							; xmm1 = ycenter
                							; xmm2 = magnification, denominator
                							; xmm3 = minsize
.break:

               	mov r8, r12  				; minsize = r8 = min(xsize, ysize)
               	cmp r8, r13  				; if xsize <= ysize
               	jle .continue 					; goto .continue
               	mov r8, r13  				; minsize = ysize
.continue:
				sub r8, 1 					; minsize = minsize - 1
				cvtsi2sd xmm3, r8
				mulsd xmm2, xmm3			; denominator = magnification * minsize
				mov rax, r12 				; numx = r8 = (column - xsize / 2)
				mov rdx, 0
				mov r8, 2
				div r8
				mov r8, [rbp - 16]			; copy col into r8
				sub r8, rax
				push r8						; numx [-40]
				mov rax, r13				; numy = r9 = (row - ysize / 2)
				mov rdx, 0
				mov r9, 2
				div r9
				mov r9, [rbp - 24]			; copy row into r9
				sub r9, rax
				push r9						; numy [-48]
.outer_loop:								; while
				cmp r14, [rbp - 32]				; if y_index >= antialias
				jge .end_outer						; goto .end_outer
.inner_loop:									; while
				cmp r15, [rbp - 32]					; if x_index >= antialias
				jge .end_inner							; goto .end_inner

				mov r8, [rbp - 40]
				cvtsi2sd xmm3, r8
				addsd xmm3, [subpixelOffsets + r15 * 8] ; colx = numx + subpixelOffsets[x_index]
				divsd xmm3, xmm2
				addsd xmm0, xmm3					; x = xcenter + colx / denominator

				mov r9, [rbp - 48]
				cvtsi2sd xmm3, r9					
				addsd xmm3, [subpixelOffsets + r14 * 8]	; coly = numy + subpixelOffsets[y_index]	
				divsd xmm4, xmm2
				subsd xmm1, xmm3					; y = ycenter - rowy / denominator

				mov rdi, [rbp - 8]
				call mandel							; iters = mandel(maxiters, x, y)

				mov rdi, rax
				call getColor						; color = getColor(iters)
				mov [buffer + rbx], rax				; buffer[total_colors] = color
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
                pop rbp
                pop rbx
                pop r15
				pop r14
				pop r13
				pop r12
				ret


