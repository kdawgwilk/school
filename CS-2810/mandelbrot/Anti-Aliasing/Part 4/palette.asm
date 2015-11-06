global palette, palette_size

section .data

palette:
            ; reds
            dq 0x0f0000
            dq 0x1f0000
            dq 0x2f0000
            dq 0x3f0000
            dq 0x4f0000
            dq 0x5f0000
            dq 0x6f0000
            dq 0x7f0000
            dq 0x8f0000
            dq 0x9f0000
            dq 0xaf0000
            dq 0xbf0000
            dq 0xcf0000
            dq 0xdf0000
            dq 0xef0000
            dq 0xff0000
            dq 0xef0000
            dq 0xdf0000
            dq 0xcf0000
            dq 0xbf0000
            dq 0xaf0000
            dq 0x9f0000
            dq 0x8f0000
            dq 0x7f0000
            dq 0x6f0000
            dq 0x5f0000
            dq 0x4f0000
            dq 0x3f0000
            dq 0x2f0000
            dq 0x1f0000
            dq 0x0f0000

            ; blues
            dq 0x00000f
            dq 0x00001f
            dq 0x00002f
            dq 0x00003f
            dq 0x00004f
            dq 0x00005f
            dq 0x00006f
            dq 0x00007f
            dq 0x00008f
            dq 0x00009f
            dq 0x0000af
            dq 0x0000bf
            dq 0x0000cf
            dq 0x0000df
            dq 0x0000ef
            dq 0x0000ff
            dq 0x0000ef
            dq 0x0000df
            dq 0x0000cf
            dq 0x0000bf
            dq 0x0000af
            dq 0x00009f
            dq 0x00008f
            dq 0x00007f
            dq 0x00006f
            dq 0x00005f
            dq 0x00004f
            dq 0x00003f
            dq 0x00002f
            dq 0x00001f
            dq 0x00000f

palette_size:
            dq ($-palette) / 8
