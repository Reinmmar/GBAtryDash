#include "level.h"
#include "build_level.h"
#include "player.h"

bn::vector<LevelData *, 100> loadedData;
bn::vector<LevelData *, 16> hitboxData;

void removeSprite(int &index) {
  if (index < 0)
    return;
  if (index >= data.size()) return;

  for (int i = 0; i < loadedData.size(); i++) {
    if (loadedData[i] == &data[index]) {
      loadedData.erase(loadedData.begin() + i);
      break;
    }
  }
  data.erase(data.begin() + index);

  index -= 1;
}

bn::fixed getObjX(LevelData obj) {
  bn::fixed cameraOffset = -120 + 8 - cameraX;
  return obj.x * 16 + cameraOffset;
}
bn::fixed getObjY(LevelData obj) {
  bn::fixed yOffset = 80 - 8 - 32;
  return -obj.y * 16 + yOffset;
}
void moveLevel() {
  for (int i = 0; i < data.size(); i++) {
    if (data.size() <= 50)
      loadNextPart = true;
    if (!data[i].sprite.has_value())
      continue;
    data[i].sprite->set_x(data[i].sprite->x() - LEVEL_SPEED);
    data[i].sprite->set_y(getObjY(data[i]) - cameraY);
  }
}
void readLevelData() {
  hitboxData.clear();
  for (int i = 0; i < data.size(); i++) {
    LevelData &notCulled = data[i];
    bn::fixed objX = getObjX(notCulled);
    bn::fixed objY = getObjY(notCulled);
    
    if (objX < -128 - 16 || objX > 128 + 16) {
      if (objX < -128 - 16) {
        removeSprite(i);
      }
      continue;
    }
    if (!notCulled.sprite.has_value()) {
      loadedData.push_back(&notCulled);
    }
    if (objX < -120 / 3 + 16 + 16 && objX > -120 / 3 - 16 - 16 &&
        objY < oy + 16 + 16 && objY > oy - 16 - 16 &&
        !(notCulled.id == DETAILED_BLOCK_CENTER ||
          notCulled.id == DECO_STICK_LARGE || notCulled.id == DECO_STICK ||
          notCulled.id == SPIKE_DECO || notCulled.id == NORMAL_FACE))
      hitboxData.emplace_back(&notCulled);
  }
  for (int i = 0; i < loadedData.size(); i++) {
    auto object = loadedData[i];
    if (object->sprite.has_value())
      continue;
    bn::fixed gridX = getObjX(*object);
    bn::fixed gridY = getObjY(*object);

    switch (object->id) {
    case BLOCK:
      object->sprite =
          bn::sprite_items::block.create_sprite(gridX, gridY);
      break;
    case DETAILED_BLOCK_PILLAR:
      if (object->rot == 90 || object->rot == 270) {
        object->sprite =
            bn::sprite_items::detailed_block_pillar_rotated.create_sprite(
                gridX, gridY);
      } else
        object->sprite =
            bn::sprite_items::detailed_block_pillar.create_sprite(gridX, gridY);
      break;
    case DETAILED_BLOCK_PILLAR_TRIPLE:
      object->sprite =
          bn::sprite_items::detailed_block_pillar_triple.create_sprite(gridX,
                                                                       gridY);
      break;
    case DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED:
      object->sprite =
          bn::sprite_items::detailed_block_pillar_triple_rotated.create_sprite(
              gridX, gridY);
      break;
    case DETAILED_BLOCK_SIDE:
      if (object->rot == 90 || object->rot == 270) {
        if (object->rot == 90)
          object->flipX = true;
        object->sprite =
            bn::sprite_items::detailed_block_side_rotated.create_sprite(gridX,
                                                                        gridY);
      } else
        object->sprite =
            bn::sprite_items::detailed_block_side.create_sprite(gridX, gridY);
      break;
    case DETAILED_BLOCK_END:
      if (object->rot == 90 || object->rot == 270) {
        if (object->rot == 90)
          object->flipX = true;
        object->sprite =
            bn::sprite_items::detailed_block_end_rotated.create_sprite(gridX,
                                                                       gridY);
      } else
        object->sprite =
            bn::sprite_items::detailed_block_end.create_sprite(gridX, gridY);
      break;
    case DETAILED_BLOCK_CORNER:
      object->sprite =
          bn::sprite_items::detailed_block_corner.create_sprite(gridX, gridY);
      break;
    case DETAILED_BLOCK_CORNER_INVERTED:
      object->sprite =
          bn::sprite_items::detailed_block_corner_inverted.create_sprite(gridX,
                                                                         gridY);
      break;
    case DETAILED_BLOCK_CENTER:
      object->sprite =
          bn::sprite_items::detailed_block_center.create_sprite(gridX, gridY);
      break;
    case HALF_BLOCK:
      object->sprite =
          bn::sprite_items::half_block.create_sprite(gridX, gridY);
      break;
    case SPIKE:
      object->sprite =
          bn::sprite_items::spike.create_sprite(gridX, gridY);
      break;
    case SPIKE_SHORT:
      object->sprite =
          bn::sprite_items::spike_short.create_sprite(gridX, gridY);
      break;
    case GROUND_SPIKES:
      object->sprite =
          bn::sprite_items::groundspikes.create_sprite(gridX, gridY);
      break;
    case DECO_STICK_LARGE:
      object->sprite =
          bn::sprite_items::deco_stick_large.create_sprite(gridX, gridY);
      break;
    case DECO_STICK:
      object->sprite =
          bn::sprite_items::deco_stick.create_sprite(gridX, gridY);
      object->sprite->set_rotation_angle(360 - object->rot);
      break;
    case NORMAL_FACE:
      object->sprite =
          bn::sprite_items::normal_face.create_sprite(gridX, gridY);
      break;
    case SPIKE_DECO:
      object->sprite =
          bn::sprite_items::spike_deco.create_sprite(gridX, gridY);
      object->sprite->set_z_order(1);
      break;
    case SHIP_PORTAL:
      object->sprite =
          bn::sprite_items::ship_portal.create_sprite(gridX, gridY);
      break;
    case CUBE_PORTAL:
      object->sprite =
          bn::sprite_items::cube_portal.create_sprite(gridX, gridY);
      break;
    default:
      break;
    }
    if (object->flipX)
      object->sprite->set_horizontal_flip(true);
    if (object->flipY)
      object->sprite->set_vertical_flip(true);
  }
}

bool dieCheck() {
  bn::fixed solidRight = icn->x() + 3;
  bn::fixed solidLeft = icn->x() - 3;
  bn::fixed solidDown = icn->y() + 3;
  bn::fixed solidUp = icn->y() - 3;
  for (int i = 0; i < loadedData.size(); i++) {
    bn::fixed objX = getObjX(*loadedData[i]);
    bn::fixed objY = getObjY(*loadedData[i]);
    bn::fixed iconTop = icn->y() - 8 - vy + cameraY;
    bn::fixed iconBottom = icn->y() + 8 - vy + cameraY;
    bn::fixed iconLeft = icn->x() - 8 + 2.75;
    bn::fixed iconRight = icn->x() + 8 + 2.75;
    switch (loadedData[i]->id) {
    case SHIP_PORTAL:
      if (iconTop <= objY + 16 && iconBottom >= objY - 16 &&
          iconRight >= objX - 10 && iconLeft <= objX + 8)
        gameMode = SHIP;
      break;
    case CUBE_PORTAL:
      if (iconTop <= objY + 16 && iconBottom >= objY - 16 &&
          iconRight >= objX - 10 && iconLeft <= objX + 8)
        gameMode = CUBE;
      break;
    default:
      break;
    }
    switch (loadedData[i]->id) {
    case BLOCK:
    case DETAILED_BLOCK_PILLAR:
    case DETAILED_BLOCK_SIDE:
    case DETAILED_BLOCK_CORNER:
    case DETAILED_BLOCK_CORNER_INVERTED:
    case DETAILED_BLOCK_END:
      if (solidRight >= objX - 8 && solidLeft <= objX + 8) {
        if (solidDown + cameraY >= objY - 8 && solidUp + cameraY <= objY + 8)
          return true;
      }
      break;
    case HALF_BLOCK:
      if (solidRight >= objX - 8 && solidLeft <= objX + 8) {
        if (solidDown + cameraY >= objY - 8 && solidUp + cameraY <= objY)
          return true;
      }
      break;
    case DETAILED_BLOCK_PILLAR_TRIPLE:
      if (solidRight >= objX - 8 && solidLeft <= objX + 8) {
        if (solidDown + cameraY >= objY - 8 - 16 &&
            solidUp + cameraY <= objY + 8 + 16)
          return true;
      }
      break;
    case DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED:
      if (solidRight >= objX - 8 - 16 && solidLeft <= objX + 8 + 16) {
        if (solidDown + cameraY >= objY - 8 && solidUp + cameraY <= objY + 8)
          return true;
      }
      break;
    case SPIKE:
      if (icn->x() + 8 >= objX - 2 && icn->x() - 8 <= objX + 2) {
        if (icn->y() + 8 + cameraY >= objY - 3 &&
            icn->y() - 8 + cameraY <= objY + 4)
          return true;
      }
      break;
    case SPIKE_SHORT:
      if (icn->x() + 8 >= objX - 2 && icn->x() - 8 <= objX + 2) {
        if (icn->y() + 8 + cameraY >= objY + 2 &&
            icn->y() - 8 + cameraY <= objY + 5)
          return true;
      }
      break;
    case GROUND_SPIKES:
      if (icn->x() + 8 >= objX - 2 && icn->x() - 8 <= objX + 2) {
        if (icn->y() + 8 + cameraY >= objY + 4 &&
            icn->y() - 8 + cameraY <= objY + 9)
          return true;
      }
      break;
    default:
      break;
    }
  }
  return false;
}
