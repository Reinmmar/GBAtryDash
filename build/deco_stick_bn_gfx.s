
@{{BLOCK(deco_stick_bn_gfx)

@=======================================================================
@
@	deco_stick_bn_gfx, 16x16@4, 
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
	.global deco_stick_bn_gfxTiles		@ 128 unsigned chars
	.hidden deco_stick_bn_gfxTiles
deco_stick_bn_gfxTiles:
	.word 0x00000000,0x00000000,0xD0000000,0xD0000000,0x00000000,0xF0000000,0xF0000000,0x00000000
	.word 0x00000000,0x00000000,0x0000000D,0x0000000D,0x00000000,0x0000000F,0x0000000F,0x00000000
	.word 0xF0000000,0xF0000000,0x00000000,0xF0000000,0xF0000000,0x00000000,0xF0000000,0xFF000000
	.word 0x0000000F,0x0000000F,0x00000000,0x0000000F,0x0000000F,0x00000000,0x0000000F,0x000000FF

	.section .rodata
	.align	2
	.global deco_stick_bn_gfxPal		@ 32 unsigned chars
	.hidden deco_stick_bn_gfxPal
deco_stick_bn_gfxPal:
	.hword 0x001F,0x7FFF,0x7FFF,0x7CC6,0x7FFF,0x7FFF,0x7FFF,0x7FFF
	.hword 0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x54A5,0x4400,0x7FFF,0x0000

@}}BLOCK(deco_stick_bn_gfx)
