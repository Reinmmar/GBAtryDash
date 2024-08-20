#ifndef BN_SPRITE_ITEMS_CUBE_PORTAL_H
#define BN_SPRITE_ITEMS_CUBE_PORTAL_H

#include "bn_sprite_item.h"

//{{BLOCK(cube_portal_bn_gfx)

//======================================================================
//
//	cube_portal_bn_gfx, 32x64@4, 
//	+ palette 16 entries, not compressed
//	+ 32 tiles not compressed
//	Total size: 32 + 1024 = 1056
//
//	Time-stamp: 2024-08-20, 16:22:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CUBE_PORTAL_BN_GFX_H
#define GRIT_CUBE_PORTAL_BN_GFX_H

#define cube_portal_bn_gfxTilesLen 1024
extern const bn::tile cube_portal_bn_gfxTiles[32];

#define cube_portal_bn_gfxPalLen 32
extern const bn::color cube_portal_bn_gfxPal[16];

#endif // GRIT_CUBE_PORTAL_BN_GFX_H

//}}BLOCK(cube_portal_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cube_portal(sprite_shape_size(sprite_shape::TALL, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(cube_portal_bn_gfxTiles, 32), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(cube_portal_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

