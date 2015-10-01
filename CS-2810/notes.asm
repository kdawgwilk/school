
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
