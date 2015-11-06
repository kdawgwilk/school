
global blendColors

section .text
blendColors:							; blendColors(buffer, count) → RGB
				push rbx					; index
				push r12					; red_total
				push r13					; green_total
				push r14					; blue_total
				push r15					; curr_color

				mov rbx, 0					; index = 0
				mov r12, 0					; red_total = 0
				mov r13, 0					; green_total = 0
				mov r14, 0					; blue_total = 0

.loop:										; while
				cmp rbx, rsi					; if index < count
				jge .end_loop						; goto .end_loop

				mov r15, [rdi +	rbx * 8]		; curr_color = buffer[index]
				mov rax, r15					; tmp = curr_color

				and rax, 255 					; mask and keep only 8 bits
				add r14, rax					; blue_total += curr_color[blue]

				mov rax, r15

				shr rax, 8 						; moves
				and rax, 255 					; mask and keep only 8 bits
				add r13, rax					; green_total += curr_color[green]

				mov rax, r15

				shr rax, 16 					; moves
				and rax, 255 					; mask and keep only 8 bits
				add r12, rax					; red_total += curr_color[red]

				inc rbx							; index++
				jmp .loop
.end_loop:									; endwhile
				mov rdx, 0
				mov rax, r12
				div rsi						; red_total /= count
				mov r12, rax

				mov rdx, 0
				mov rax, r13
				div rsi						; green_total /= count
				mov r13, rax

				mov rdx, 0
				mov rax, r14
				div rsi						; blue_total /= count
				mov r14, rax

				mov r15, 0					; color = 0
				add r15, r12				; color = red << 8
				shl r15, 8
				add r15, r13				; color = green << 8
				shl r15, 8
				add r15, r14				; color = blue << 8
				mov rax, r15

				pop r15
				pop r14
				pop r13
				pop r12
				pop rbx

				ret


