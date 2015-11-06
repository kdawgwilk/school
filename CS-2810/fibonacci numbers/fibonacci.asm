global fibonacci

; write your code here
section .text
fibonacci:							; int fibonacci(int n) {
				mov rsi, 2			;     int i = 2;          // use rsi for i
				mov rdx, 1			;     int a = 1;          // use rdx for a
				mov rax, 1			;     int b = 1;          // use rax for b
.loop:
				cmp rsi, rdi		;     if (i >= n)
				jge .end			;         goto end;

				mov rcx, rdx		;     int temp = a + b;   // use rcx for temp
				add rcx, rax
				mov rdx, rax		;     a = b;
				mov rax, rcx		;     b = temp;
				add rsi, 1			;     i = i + 1;
				jmp .loop			;     goto loop;
.end:							
				ret					;     return b;
									