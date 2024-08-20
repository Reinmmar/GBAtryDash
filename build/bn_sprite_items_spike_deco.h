#ifndef BN_SPRITE_ITEMS_SPIKE_DECO_H
#define BN_SPRITE_ITEMS_SPIKE_DECO_H

#include "bn_sprite_item.h"

//{{BLOCK(spike_deco_bn_gfx)

//======================================================================
//
//	spike_deco_bn_gfx, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2024-08-20, 16:22:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPIKE_DECO_BN_GFX_H
#define GRIT_SPIKE_DECO_BN_GFX_H

#define spike_deco_bn_gfxTilesLen 2048
extern const bn::tile spike_deco_bn_gfxTiles[64];

#define spike_deco_bn_gfxPalLen 32
extern const bn::color spike_deco_bn_gfxPal[16];

#endif // GRIT_SPIKE_DECO_BN_GFX_H

//}}BLOCK(spike_deco_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item spike_deco(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(spike_deco_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(spike_deco_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

