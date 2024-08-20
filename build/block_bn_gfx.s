
@{{BLOCK(block_bn_gfx)

@=======================================================================
@
@	block_bn_gfx, 16x16@4, 
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
	.global block_bn_gfxTiles		@ 128 unsigned chars
	.hidden block_bn_gfxTiles
block_bn_gfxTiles:
	.word 0xEEEEEEEE,0xFFFFFFFE,0xFFFFFFFE,0xFFFFFFFE,0xFFFFFFFE,0xFFFFFFFE,0xDFFFDFFE,0xFFDFFFDE
	.word 0xEEEEEEEE,0xEFFFFFFF,0xEFFFFFFF,0xEFFFFFFF,0xEFFFFFFF,0xEFFFFFFF,0xEFFFDFFF,0xEFDFFFDF
	.word 0xFDFDFDFE,0xDFDFDFDE,0xFDFDFDFE,0xDFDFDFDE,0xDDFDDDFE,0xFDDDFDDE,0xDDDDDDDE,0xEEEEEEEE
	.word 0xEDFDFDFD,0xEFDFDFDF,0xEDFDFDFD,0xEFDFDFDF,0xEDFDDDFD,0xEDDDFDDD,0xEDDDDDDD,0xEEEEEEEE

	.section .rodata
	.align	2
	.global block_bn_gfxPal		@ 32 unsigned chars
	.hidden block_bn_gfxPal
block_bn_gfxPal:
	.hword 0x7C1F,0x0BE0,0x7F40,0x7CC6,0x001F,0x001F,0x001F,0x001F
	.hword 0x001F,0x001F,0x001F,0x001F,0x001F,0x4400,0x7FFF,0x0000

@}}BLOCK(block_bn_gfx)
