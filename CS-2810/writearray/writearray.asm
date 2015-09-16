global writearray
extern itoa

newline:		equ 10

section .text
writearray:
				; writearray(buffer, array, length) -> # bytes written
					; for i = 0; i < length; i++ {
						; count += itoa(buffer + count, array[i])
						; buffer[count] = ''
						; count++
					; }
					; buffer[count - 1] = 10
					; return count

				; writearray(buffer, array, length) -> # bytes written

				push rbx	; rbx = buffer
				push r12	; r12 = array
				push r13	; r13 = length
				push r14	; r14 = count
				push r15	; r15 = i

				mov rbx, rdi
				mov r12, rsi
				mov r13, rdx
				mov r14, 0
				mov r15, 0

.loop:
				; if i >= length: goto .end
				cmp r15, r13
				jge .end


				; itoa(buffer + count, array[i])
				lea rdi, [rbx + r14]
				mov rsi, [r12 + r15 * 8]
				call itoa

				; count += rax
				add r14, rax

				; buffer[count] = ' '; count++
				mov [rbx + r14], byte ' '
				inc r14
				inc r15

				jmp .loop


.end:
				; buffer
				mov [rbx + r14 - 1], byte newline

				; return count
				mov rax, r14

				pop r15
				pop r14
				pop r13
				pop r12
				pop rbx

				ret





