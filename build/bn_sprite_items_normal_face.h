#ifndef BN_SPRITE_ITEMS_NORMAL_FACE_H
#define BN_SPRITE_ITEMS_NORMAL_FACE_H

#include "bn_sprite_item.h"

//{{BLOCK(normal_face_bn_gfx)

//======================================================================
//
//	normal_face_bn_gfx, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2024-08-20, 16:22:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_NORMAL_FACE_BN_GFX_H
#define GRIT_NORMAL_FACE_BN_GFX_H

#define normal_face_bn_gfxTilesLen 2048
extern const bn::tile normal_face_bn_gfxTiles[64];

#define normal_face_bn_gfxPalLen 32
extern const bn::color normal_face_bn_gfxPal[16];

#endif // GRIT_NORMAL_FACE_BN_GFX_H

//}}BLOCK(normal_face_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item normal_face(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(normal_face_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(normal_face_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

