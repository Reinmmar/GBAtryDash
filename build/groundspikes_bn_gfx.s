
@{{BLOCK(groundspikes_bn_gfx)

@=======================================================================
@
@	groundspikes_bn_gfx, 16x16@4, 
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
	.global groundspikes_bn_gfxTiles		@ 128 unsigned chars
	.hidden groundspikes_bn_gfxTiles
groundspikes_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0xF0F000F0,0xFFFF0FFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF
	.word 0x00000000,0x0000000F,0x0000000F,0xF00F00FF,0xF0FF0FFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF

	.section .rodata
	.align	2
	.global groundspikes_bn_gfxPal		@ 32 unsigned chars
	.hidden groundspikes_bn_gfxPal
groundspikes_bn_gfxPal:
	.hword 0x7C1F,0x0BE0,0x7F40,0x7CC6,0x001F,0x001F,0x001F,0x001F
	.hword 0x001F,0x001F,0x001F,0x001F,0x001F,0x4400,0x7FFF,0x0000

@}}BLOCK(groundspikes_bn_gfx)
