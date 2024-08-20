#ifndef BN_SPRITE_ITEMS_BLOCK_H
#define BN_SPRITE_ITEMS_BLOCK_H

#include "bn_sprite_item.h"

//{{BLOCK(block_bn_gfx)

//======================================================================
//
//	block_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-08-20, 16:22:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BLOCK_BN_GFX_H
#define GRIT_BLOCK_BN_GFX_H

#define block_bn_gfxTilesLen 128
extern const bn::tile block_bn_gfxTiles[4];

#define block_bn_gfxPalLen 32
extern const bn::color block_bn_gfxPal[16];

#endif // GRIT_BLOCK_BN_GFX_H

//}}BLOCK(block_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item block(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(block_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(block_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

