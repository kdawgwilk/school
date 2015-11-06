
; jmp addr; jump always
; je addr; jump if dst == src
; jne addr; jump if dst != src
; jl addr; jump if dst < src (2s complement comparison)
; jle addr; jump if dst <= src (2s complement comparison)
; jg addr; jump if dst > src (2s comparison comparison)
; jge addr; jump if dst >= src (2s comparison comparison)
; jb addr; jump if dst < src (unsigned/float comparison)
; jbe addr; jump if dst <= src (unsigned/float comparison)
; ja addr; jump if dst > src (unsigned/float comparison)
; jae addr; jump if dst >= src (unsigned/float comparison)

; movsd xmm0, xmm1 ; move a scalar double (a single 64-bit float) from xmm1 to xmm2
; addsd xmm0, xmm1 ; add two floats (xmm0 gets the result)
; subsd xmm0, xmm1 ; subtraction (xmm0 -= xmm1)
; mulsd xmm0, xmm1 ; xmm0 = xmm0 × xmm1
; divsd xmm0, xmm1 ; xmm0 = xmm0 / xmm1

; comisd xmm0, xmm1 ; compare xmm0 with xmm1, set flags based on result

; cvtsi2sd xmm0, rax ; convert the integer in rax to a double in xmm0

; rdi = maxIterations
; xmm0 = x
; xmm1 = y
; xmm2: a
; xmm3: b
; xmm4: a²
; xmm5: b²
; xmm6: a² + b²
; xmm7: 4.0



; Midterm notes for midterm

; [0] [011] [1010]
; [0] = sign +/- // 0 = positive, 1 =  negative
; [011] = exponent bits
; [1010] = fractional bits

; denormalized numbers
; exponent bits = 000
; exponent value = 1 - bias = -2 // (bias = 2^(k-1)-1 = 3 // k = # exponent bits)
; fraction value = 0.bits

; 0 000 1010
; 0.1010 = 5/8 * 1/4 = 5/32
; 0 000 0000 = 0
; 1 000 0000 = -0

; 0 000 0000 = 0		// smallest denormalized number
; 0 000 0001 = 1/64
; 0 000 0010 = 2/64
; 0 000 0011 = 3/64
; ...
; 0 000 1111 = 15/64	// largest denormalized number

; 0 001 0000 = 16/54	// smallest normalized number
; 0 001 0001 = 17/64
; ...
; 0 001 1111 = 31/64
; 0 010 0000 = 32/64 = 16/32
; 0 010 0001 = 17/32
; 0 010 0010 = 18/32
; ...
; 0 010 1111 = 31/32
; 0 011 0000 = 1 = 32/32 = 16/16
; 0 011 0001 = 17/16
; ...
; 0 101 1111 = 31/4
; 0 110 0000 = 16/2 = 32/4 = 8
; 0 110 1111 = 21/2		// largest normalized number

; 0 111 0000 = infinity

; 0 111 0001 = NaN

; normalized
; exponent bits = not all 0's, not all 1's
; exponent value = bits - bias // (bias = 2^(k-1)-1 = 3 // k = # exponent bits)
; fractional value = 1.bits

; 0 001 0000 
; fractional value = 1.0000 = 1 * 1/4 = 16/64

; special cases
; exponent bits = all 1's
; fractional bits all 0's = infinity
; else = NaN





