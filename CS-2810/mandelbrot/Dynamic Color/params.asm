global filename
global xcenter, ycenter, mag
global xsize, ysize, iters, antialias

section .data

filename:   db "fractal.ppm", 0
xcenter:    dq -0.743643135
ycenter:    dq 0.131825963
mag:        dq 91152.0
xsize:      dq 320
ysize:      dq 200
iters:      dq 1000
antialias:  dq 1
