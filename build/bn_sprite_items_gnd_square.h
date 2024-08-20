#ifndef BN_SPRITE_ITEMS_GND_SQUARE_H
#define BN_SPRITE_ITEMS_GND_SQUARE_H

#include "bn_sprite_item.h"

//{{BLOCK(gnd_square_bn_gfx)

//======================================================================
//
//	gnd_square_bn_gfx, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2024-08-20, 16:22:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GND_SQUARE_BN_GFX_H
#define GRIT_GND_SQUARE_BN_GFX_H

#define gnd_square_bn_gfxTilesLen 2048
extern const bn::tile gnd_square_bn_gfxTiles[64];

#define gnd_square_bn_gfxPalLen 32
extern const bn::color gnd_square_bn_gfxPal[16];

#endif // GRIT_GND_SQUARE_BN_GFX_H

//}}BLOCK(gnd_square_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item gnd_square(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(gnd_square_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(gnd_square_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

