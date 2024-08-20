#ifndef BN_REGULAR_BG_ITEMS_SQUARE_H
#define BN_REGULAR_BG_ITEMS_SQUARE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(square_bn_gfx)

//======================================================================
//
//	square_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 143 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 4576 + 2048 = 6656
//
//	Time-stamp: 2024-08-20, 16:22:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SQUARE_BN_GFX_H
#define GRIT_SQUARE_BN_GFX_H

#define square_bn_gfxTilesLen 4576
extern const bn::tile square_bn_gfxTiles[143];

#define square_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell square_bn_gfxMap[1024];

#define square_bn_gfxPalLen 32
extern const bn::color square_bn_gfxPal[16];

#endif // GRIT_SQUARE_BN_GFX_H

//}}BLOCK(square_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item square(
            regular_bg_tiles_item(span<const tile>(square_bn_gfxTiles, 143), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(square_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(square_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

