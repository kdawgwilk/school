; writeRGB(buffer, rgb) -> # bytes written
; write a value of the form 0x00RRGGBB to the buffer as text
; example: writeRGB(buffer, 0x010203) writes "1 2 3" to the buffer
; and returns 5.

global writeRGB
extern itoa

writeRGB:
				; writeRGB(buffer, color) -> # bytes written
				; push any previously stored values to stack
				push r12
				push r13
				push r14

                ; move passed parameters to locations that wont be touched
				mov r12, rdi
				mov r13, rsi
				mov r14, 0

				; Red
				mov rsi, r13
				shr rsi, 16 ; moves
				and rsi, 255 ; mask and keep only 8 bits

				; Call itoa(buffer, red) -> # bytes written
				lea rdi, [r12 + r14]
                ; mov rsi, rsi
                call itoa
                add r14, rax

				; Add space
				mov al, ' '
                mov [r12 + r14], al
                inc r14

				; Green
				mov rsi, r13
				shr rsi, 8
				and rsi, 255

				; Call itoa(buffer, green) -> # bytes written
				lea rdi, [r12 + r14]
                ; mov rsi, rsi
                call itoa
                add r14, rax

				; Add space
				mov al, ' '
                mov [r12 + r14], al
                inc r14

				; Blue
				mov rsi, r13
				and rsi, 255

				; Call itoa(buffer, blue) -> # bytes written
				lea rdi, [r12 + r14]
                ; mov rsi, rsi
                call itoa
                add r14, rax

                mov rax, r14

				pop r14
				pop r13
				pop r12

				ret
