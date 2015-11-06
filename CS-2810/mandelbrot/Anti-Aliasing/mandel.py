
subpixel = []

palette = [
	0x0f0000,
    0x1f0000,
    0x2f0000,
    0x3f0000,
    0x4f0000,
    0x5f0000,
    0x6f0000,
    0x7f0000,
    0x8f0000,
    0x9f0000,
    0xaf0000,
    0xbf0000,
    0xcf0000,
    0xdf0000,
    0xef0000,
    0xff0000,
    0xef0000,
    0xdf0000,
    0xcf0000,
    0xbf0000,
    0xaf0000,
    0x9f0000,
    0x8f0000,
    0x7f0000,
    0x6f0000,
    0x5f0000,
    0x4f0000,
    0x3f0000,
    0x2f0000,
    0x1f0000,
    0x0f0000,
    # blues
    0x00000f,
    0x00001f,
    0x00002f,
    0x00003f,
    0x00004f,
    0x00005f,
    0x00006f,
    0x00007f,
    0x00008f,
    0x00009f,
    0x0000af,
    0x0000bf,
    0x0000cf,
    0x0000df,
    0x0000ef,
    0x0000ff,
    0x0000ef,
    0x0000df,
    0x0000cf,
    0x0000bf,
    0x0000af,
    0x00009f,
    0x00008f,
    0x00007f,
    0x00006f,
    0x00005f,
    0x00004f,
    0x00003f,
    0x00002f,
    0x00001f,
    0x00000f
]

def getSubpixelOffset():
	for i in range(antialias):
		subpixel.append((0.5 + float(i)) / float(antialias) - 0.5)

def calcPixel(col, row):
	sizex2 = sizex2 / 2
	sizey2 = sizey2 / 2
	magminsize1 = mag * float(min(sizex2, sizey2) - 1)
	samples = []
	# 120 qw (quad words)
	for ys in range(antialias):
		for xs in range(antialias):
			x = centerx + (float(col - sizex2) + subpixel[xs]) / magminsize1
			y = centery + (float(row - sizey2) + subpixel[ys]) / magminsize1
			iters = mandel(x, y)
			color = getColor(iters)
			samples.append(color)
	return blend(samples)

def mandel (maxiters, x, y):
	a, b = x, y
	for iters in range(1, maxiters + 1):
		a2 = a * a
		b2 = b * b
		if a2 + b2 >= 4.0:
			return iters
		b =  a * b
		b = b + b +y
		a = a2 - b2 + x
	return 0

def getColor(iters):
	if iters == 0:
		return 0x000000
	i = (iters - 1) % len(palette)
	return palette[i]

def blend(samples):
	r, g, b = 0, 0, 0
	for color in samples:
		r += (color >> 16) & 0xff
		g += (color >> 8) & 0xff
		b += color & 0xff
	aa = len(samples)
	color = ((r/aa) << 16) | ((g/aa) << 8) | (b/aa)

def itoa(n):
	return str(n)

def writeRGB(buff, color):
	r = (color >> 16) & 0xff
	g = (color >> 8) & 0xff
	b = color & 0xff
	return buff + itoa(r) + ' ' + itoa(g) + ' ' + itoa(b)

def start():
	getSubpixelOffset()
	fp = open('fractal.ppm', 'w')
	fp.write('P3\n')
	fp.write(itoa(sizex) + ' ' + itoa(sizey) + '\n')
	fp.write('255\n')
	fp.flush()

	for row in range(sizey):
		for col in range(sizex):
			color = calcPixel(col, row)
			buff = writeRGB(buff, color)
			if col < sizex - 1:
				buff += ' '
			else:
				buff += '\n'
		fp.write(buff)
		fp.flush()
	fp.close()
	return

__name__ = __main__





