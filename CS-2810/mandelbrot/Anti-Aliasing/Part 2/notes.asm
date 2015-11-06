; SUBPIXEL OFFSETS
; To implement anti-aliasing, you will need to be able to identify points distributed evenly within each pixel. For example, you could divide a single pixel into 4 parts:

; +-----+-----+
; |     |     |
; |     |     |
; +-----+-----+
; |     |     |
; |     |     |
; +-----+-----+

; To compute smoother images, you will do a complete Mandelbrot computation for each of these subpixels, and then blend the colors obtained to give a single pixel in the final image.

; You will sample each subpixel right in its center. If you think of each pixel as a 1×1 square with its center at (0, 0), then its top-left corner is (-0.5, 0.5) and its bottom-right corner is (0.5, -0.5).

; The center points of the four subpixels would be:

; (-0.25, 0.25)
; (0.25, 0.25)
; (-0.25, -0.25)
; (0.25, -0.25)

; Note that the offsets from zero are the same in the horizontal and vertical directions: -0.25 and 0.25. These two offsets are combined in every possible way to give the coordinates of the center point of each pixel.

; This works for 3×3, 4×4, and higher subdivisions of a pixel. For 3×3 subpixels, the offsets would be:

; -1/3, 0, 1/3

; and for 4×4 subpixels the offsets would be:

; -0.375, -0.125, 0.125, 0.375
; Combining these offsets in every possible pairing gives the center point of each subpixel.

; You can compute these offsets by following this pseudo-code, where A is the anti-aliasing factor (2 for a 2×2 division, 3 for a 3×3 division, etc.):

; for i from 0 to A
; offset[i] = (i + 0.5) / A - 0.5

; Write a function to compute these subpixel offsets and store them in a global array of 64-bit float values:

; setupSubpixel(antialias)
; Note that it does not return anything. You should also create a global array of 64-bit float values:

; subpixelOffsets
; Make it big enough to hold 64 values. Implement setupSubpixel to fill in the n entries for an n*×*n subpixel subdivision. This function will be called once at program startup time, and after that the anti-aliasing code will reference the global subpixelOffsets array directly as needed.