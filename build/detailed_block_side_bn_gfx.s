
@{{BLOCK(detailed_block_side_bn_gfx)

@=======================================================================
@
@	detailed_block_side_bn_gfx, 16x16@4, 
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
	.global detailed_block_side_bn_gfxTiles		@ 128 unsigned chars
	.hidden detailed_block_side_bn_gfxTiles
detailed_block_side_bn_gfxTiles:
	.word 0xEEEEEEEE,0xFF33FFFF,0xFF33FFFF,0xFF33FFFF,0x33333333,0x33333333,0xDD33DDDD,0xDD33DDDD
	.word 0xEEEEEEEE,0xFFFF33FF,0xFFFF33FF,0xFFFF33FF,0x33333333,0x33333333,0xDDDD33DD,0xDDDD33DD
	.word 0xDD33DDDD,0xDD33DDDD,0x33333333,0x33333333,0xCC33CCCC,0xCC33CCCC,0xCC33CCCC,0xCC33CCCC
	.word 0xDDDD33DD,0xDDDD33DD,0x33333333,0x33333333,0xCCCC33CC,0xCCCC33CC,0xCCCC33CC,0xCCCC33CC

	.section .rodata
	.align	2
	.global detailed_block_side_bn_gfxPal		@ 32 unsigned chars
	.hidden detailed_block_side_bn_gfxPal
detailed_block_side_bn_gfxPal:
	.hword 0x7C1F,0x0BE0,0x7F40,0x7CC6,0x001F,0x001F,0x001F,0x001F
	.hword 0x001F,0x001F,0x001F,0x001F,0x54A5,0x4400,0x7FFF,0x0000

@}}BLOCK(detailed_block_side_bn_gfx)
