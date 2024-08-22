#include "level.h"
#include "build_level.h"
#include "player.h"

bn::vector<LevelData*, 100> loadedData;
bn::vector<LevelData*, 16> hitboxData;


LevelData::LevelData(int obj, bn::fixed xp, bn::fixed yp, bn::fixed r, bool fx, bool fy, int u, int ri, int d, int l) :
  id(obj),
  x(xp + 5), y(yp),
  flipX(fx), flipY(fy),
  up(u), right(ri), down(d), left(l) {
  if (r > 360) r -= 360;
  else if (r < 0) r += 360;
  rot = r;

  switch (obj) {
    case  BLOCK:
    case DETAILED_BLOCK_PILLAR:
    case DETAILED_BLOCK_PILLAR_TRIPLE:
    case DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED:
    case DETAILED_BLOCK_SIDE:
    case DETAILED_BLOCK_CORNER:
    case DETAILED_BLOCK_CORNER_INVERTED:
    case DETAILED_BLOCK_CENTER:
    case DETAILED_BLOCK_END:
    case HALF_BLOCK:
      type = SOLID;
      break;
    case SPIKE:
    case SPIKE_SHORT:
    case GROUND_SPIKES:
      type = KILL;
      break;
    case SHIP_PORTAL:
    case CUBE_PORTAL:
      type = PORTAL;
      break;
    default:
      type = NONE;
      break;
  }
};

void removeSprite(int& index) {
  if (index < 0) return;
  if (index >= data.size()) return;

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
  if (data.size() <= 50)
    loadNextPart = true;
  for (int i = 0; i < data.size(); i++) {
    if (!data[i].sprite.has_value())
      continue;
    data[i].sprite->set_x(data[i].sprite->x() - LEVEL_SPEED);
    data[i].sprite->set_y(getObjY(data[i]) - cameraY);
  }
}
void readLevelData() {
  hitboxData.clear();
  loadedData.clear();
  for (int i = 0; i < data.size(); i++) {
    LevelData& notCulled = data[i];
    bn::fixed objX = getObjX(notCulled);
    bn::fixed objY = getObjY(notCulled);

    if (objX < -128 - 16 || objX > 128 + 16) {
      if (getObjX(data[i]) < -128 - 16) {
        removeSprite(i);
      }
      continue;
    }
    loadedData.push_back(&notCulled);
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
        object->sprite = bn::sprite_items::block.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_PILLAR:
        if (object->rot == 90 || object->rot == 270) {
          object->sprite = bn::sprite_items::detailed_block_pillar_rotated.create_sprite(gridX, gridY);
        }
        else
          object->sprite = bn::sprite_items::detailed_block_pillar.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_PILLAR_TRIPLE:
        object->sprite = bn::sprite_items::detailed_block_pillar_triple.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED:
        object->sprite = bn::sprite_items::detailed_block_pillar_triple_rotated.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_SIDE:
        if (object->rot == 90 || object->rot == 270) {
          if (object->rot == 90)
            object->flipX = true;
          object->sprite = bn::sprite_items::detailed_block_side_rotated.create_sprite(gridX, gridY);
        }
        else
          object->sprite = bn::sprite_items::detailed_block_side.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_END:
        if (object->rot == 90 || object->rot == 270) {
          if (object->rot == 90)
            object->flipX = true;
          object->sprite = bn::sprite_items::detailed_block_end_rotated.create_sprite(gridX, gridY);
        }
        else
          object->sprite = bn::sprite_items::detailed_block_end.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_CORNER:
        object->sprite = bn::sprite_items::detailed_block_corner.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_CORNER_INVERTED:
        object->sprite = bn::sprite_items::detailed_block_corner_inverted.create_sprite(gridX, gridY);
        break;
      case DETAILED_BLOCK_CENTER:
        object->sprite = bn::sprite_items::detailed_block_center.create_sprite(gridX, gridY);
        break;
      case HALF_BLOCK:
        object->sprite = bn::sprite_items::half_block.create_sprite(gridX, gridY);
        break;
      case SPIKE:
        object->sprite = bn::sprite_items::spike.create_sprite(gridX, gridY);
        break;
      case SPIKE_SHORT:
        object->sprite = bn::sprite_items::spike_short.create_sprite(gridX, gridY);
        break;
      case GROUND_SPIKES:
        object->sprite = bn::sprite_items::groundspikes.create_sprite(gridX, gridY);
        break;
      case DECO_STICK_LARGE:
        object->sprite = bn::sprite_items::deco_stick_large.create_sprite(gridX, gridY);
        break;
      case DECO_STICK:
        object->sprite = bn::sprite_items::deco_stick.create_sprite(gridX, gridY);
        object->sprite->set_rotation_angle(object->rot);
        break;
      case NORMAL_FACE:
        object->sprite = bn::sprite_items::normal_face.create_sprite(gridX, gridY);
        break;
      case SPIKE_DECO:
        object->sprite = bn::sprite_items::spike_deco.create_sprite(gridX, gridY);
        object->sprite->set_z_order(1);
        break;
      case SHIP_PORTAL:
        object->sprite = bn::sprite_items::ship_portal.create_sprite(gridX, gridY);
        break;
      case CUBE_PORTAL:
        object->sprite = bn::sprite_items::cube_portal.create_sprite(gridX, gridY);
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
  const bn::fixed solidRight = icn->x() + 3;
  const bn::fixed solidLeft = icn->x() - 3;
  const bn::fixed solidDown = icn->y() + 3 + cameraY;
  const bn::fixed solidUp = icn->y() - 3 + cameraY;
  for (int i = 0; i < loadedData.size(); i++) {
    const bn::fixed objX = getObjX(*loadedData[i]);
    const bn::fixed objY = getObjY(*loadedData[i]);
    const bn::fixed iconTop = icn->y() - 8 + cameraY;
    const bn::fixed iconBottom = icn->y() + 8 + cameraY;
    const bn::fixed iconLeft = icn->x() - 8;
    const bn::fixed iconRight = icn->x() + 8;


    const bn::fixed objUp = objY - loadedData[i]->up;
    const bn::fixed objLeft = objX - loadedData[i]->left;
    const bn::fixed objRight = objX + loadedData[i]->right;
    const bn::fixed objDown = objY + loadedData[i]->down;

    if (objLeft == 0 && objRight == 0 && objUp == 0 && objDown == 0)
      continue;

    switch (loadedData[i]->type) {
      case SOLID:
        if (solidRight >= objLeft && solidLeft <= objRight && solidDown >= objUp && solidUp <= objDown)
          return true;
        break;
      case KILL:
        if (iconRight >= objLeft && iconLeft <= objRight && iconBottom >= objUp && iconTop <= objDown)
          return true;
        break;
      case PORTAL:
        if (iconTop <= objDown && iconBottom >= objUp && iconRight >= objLeft && iconLeft <= objRight)
          gameMode = loadedData[i]->id - CUBE_PORTAL;
        break;
      default:
        break;
    }
  }
  return false;
}
