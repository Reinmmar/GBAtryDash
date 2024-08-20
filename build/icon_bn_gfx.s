
@{{BLOCK(icon_bn_gfx)

@=======================================================================
@
@	icon_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2024-08-20, 16:22:56
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global icon_bn_gfxTiles		@ 128 unsigned chars
	.hidden icon_bn_gfxTiles
icon_bn_gfxTiles:
	.word 0xFFFFFFF0,0x1111111F,0x1111111F,0x1111111F,0xFFFF111F,0xFFFF111F,0x22FF111F,0x22FF111F
	.word 0x0FFFFFFF,0xF1111111,0xF1111111,0xF1111111,0xF111FFFF,0xF111FFFF,0xF111FF22,0xF111FF22
	.word 0x22FF111F,0x22FF111F,0xFFFF111F,0xFFFF111F,0x1111111F,0x1111111F,0x1111111F,0xFFFFFFF0
	.word 0xF111FF22,0xF111FF22,0xF111FFFF,0xF111FFFF,0xF1111111,0xF1111111,0xF1111111,0x0FFFFFFF

	.section .rodata
	.align	2
	.global icon_bn_gfxPal		@ 32 unsigned chars
	.hidden icon_bn_gfxPal
icon_bn_gfxPal:
	.hword 0x7C1F,0x0BE0,0x7F40,0x7CC6,0x001F,0x001F,0x001F,0x001F
	.hword 0x001F,0x001F,0x001F,0x001F,0x001F,0x4400,0x2000,0x0000

@}}BLOCK(icon_bn_gfx)
