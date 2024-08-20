
@{{BLOCK(spike_short_bn_gfx)

@=======================================================================
@
@	spike_short_bn_gfx, 16x16@4, 
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
	.global spike_short_bn_gfxTiles		@ 128 unsigned chars
	.hidden spike_short_bn_gfxTiles
spike_short_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xE0000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0000000E
	.word 0xFE000000,0xDFE00000,0xFFDE0000,0xFDFDE000,0xDFDFDE00,0xDDFDDDE0,0xFDDDFDDE,0xEEEEEEEE
	.word 0x000000EF,0x00000EFF,0x0000EFDF,0x000EFDFD,0x00EFDFDF,0x0EDDDDFD,0xEDDDFDDD,0xEEEEEEEE

	.section .rodata
	.align	2
	.global spike_short_bn_gfxPal		@ 32 unsigned chars
	.hidden spike_short_bn_gfxPal
spike_short_bn_gfxPal:
	.hword 0x7C1F,0x0BE0,0x7F40,0x7CC6,0x001F,0x001F,0x001F,0x001F
	.hword 0x001F,0x001F,0x001F,0x001F,0x001F,0x4400,0x7FFF,0x0000

@}}BLOCK(spike_short_bn_gfx)
