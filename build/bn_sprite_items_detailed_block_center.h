#ifndef BN_SPRITE_ITEMS_DETAILED_BLOCK_CENTER_H
#define BN_SPRITE_ITEMS_DETAILED_BLOCK_CENTER_H

#include "bn_sprite_item.h"

//{{BLOCK(detailed_block_center_bn_gfx)

//======================================================================
//
//	detailed_block_center_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-08-20, 16:22:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DETAILED_BLOCK_CENTER_BN_GFX_H
#define GRIT_DETAILED_BLOCK_CENTER_BN_GFX_H

#define detailed_block_center_bn_gfxTilesLen 128
extern const bn::tile detailed_block_center_bn_gfxTiles[4];

#define detailed_block_center_bn_gfxPalLen 32
extern const bn::color detailed_block_center_bn_gfxPal[16];

#endif // GRIT_DETAILED_BLOCK_CENTER_BN_GFX_H

//}}BLOCK(detailed_block_center_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item detailed_block_center(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(detailed_block_center_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(detailed_block_center_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

