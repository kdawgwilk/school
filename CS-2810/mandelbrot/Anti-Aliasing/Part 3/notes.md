# CALCPIXEL REVISITED
It is time to update `calcPixel` to implement antialiasing. First, it will need an additional argument:

 * `calcPixel(maxiters, column, row, xsize, ysize, antialias, xcenter, ycenter, magnification) → rgb`

The `antialias` parameter tells how aggressively to oversample each pixel. A factor of 1 is a normal computation. A factor of 2 divides each pixel into 2×2 subpixels, 3 divides each pixel into 3×3 subpixels, etc.

Add a buffer (use the `.bss` segment) where you can store the color of each subpixel as you go. 4096 entries will support up to 64×64 antialiasing. If you want to go higher, you can.

`calcPixel` should implement this pseudo-code:
```
denominator = magnification * (minsize - 1)
for yi in range(0, antialias)
    for xi in range(0, antialias)
        x = xcenter + ((column - xsize/2) + subpixelOffsets[xi]) / denominator
        y = ycenter - ((row - ysize/2) + subpixelOffsets[yi]) / denominator
        iters = mandel(maxiters, x, y)
        color = getColor(iters)
        append color to list of colors
return blendColors(color list, number of colors)
```
## Hints

 * As before, compute the denominator once and use it in the computation of x and y
 * Compute as much as you can using integers, and then convert to floats for the parts that require it

There are too many values to store everything in registers (especially across multiple calls to other functions). Here is one approach to managing the many variables this function needs:

 * Start by pushing rbp onto the stack. You must restore this value before the function returns.

 * Copy rsp to rbp. You will use rbp as a known point on the stack

 * Push all of the values that you will need onto the stack. For each one, including a comment that shows how far below rbp that value sits on the stack. For example, if you started by pushing rdi onto the stack, you might have:
```push rdi ; maxiters     [-8]```
This indicates that the value you pushed onto the stack (from rdi) is the maxiters parameters, and it sits 8 bytes below where rbp points. The next value would be 16 bytes below, and so forth.

 * To store a value from a float register, implement the steps of a `push` command manually:
```
sub rsp, 8
movsd [rsp], xmm0 ; centerx [-56]
```

 * You can still use the stack to free up some callee-saved registers for loop variables and other values that need to survive across function calls. Push them after pushing your other parameters that do not need the convenience of a register.

 * When you need to use one of these values, identify it by its offset from rbp:
```
mov rax, [rbp - 16] ; copy column into rax
```

 * When cleaning up at the end, pop any registers that you pushed that need to be restored.

 * For some values, you may not need to pop them anywhere, but you still need them off the stack. You can clean them up by moving the stack pointer directly:
```
mov rsp, rbp
pop rbp
ret
```

This is a common pattern to end a function.