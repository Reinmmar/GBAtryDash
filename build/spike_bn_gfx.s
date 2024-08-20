
@{{BLOCK(spike_bn_gfx)

@=======================================================================
@
@	spike_bn_gfx, 16x16@4, 
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
	.global spike_bn_gfxTiles		@ 128 unsigned chars
	.hidden spike_bn_gfxTiles
spike_bn_gfxTiles:
	.word 0xE0000000,0xE0000000,0xFE000000,0xFE000000,0xFFE00000,0xFFE00000,0xDFFE0000,0xFFDE0000
	.word 0x0000000E,0x0000000E,0x000000EF,0x000000EF,0x00000EFF,0x00000EFF,0x0000EFFF,0x0000EFDF
	.word 0xFDFDE000,0xDFDFE000,0xFDFDFE00,0xDFDFDE00,0xDDFDDDE0,0xFDDDFDE0,0xDDDDDDDE,0xEEEEEEEE
	.word 0x000EFDFD,0x000EDFDF,0x00EDFDFD,0x00EFDFDF,0x0EFDDDFD,0x0EDDFDDD,0xEDDDDDDD,0xEEEEEEEE

	.section .rodata
	.align	2
	.global spike_bn_gfxPal		@ 32 unsigned chars
	.hidden spike_bn_gfxPal
spike_bn_gfxPal:
	.hword 0x7C1F,0x0BE0,0x7F40,0x7CC6,0x001F,0x001F,0x001F,0x001F
	.hword 0x001F,0x001F,0x001F,0x001F,0x001F,0x4400,0x7FFF,0x0000

@}}BLOCK(spike_bn_gfx)
