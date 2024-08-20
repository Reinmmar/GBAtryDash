#include "player.h"
#include "build_level.h"
#include "level.h"
int gameMode = CUBE;
bn::fixed rotAngle = 0;

void handleLand() {
  onGround = false;
  underCeiling = false;
  if (oy + 8 > 48) {
    oy = 48 - 8;
    icn->set_y(oy - cameraY);
    vy = 0;
    icn->set_rotation_angle(0);
    onGround = true;
    return;
  } else if (gameMode == SHIP || gameMode == UFO) {
    if (icn->y() - 8 < -80) {
      underCeiling = true;
      oy = -80 + 8 + cameraY;
      icn->set_y(oy - cameraY);
      icn->set_rotation_angle(0);
      vy = 0;
      return;
    } else if (icn->y() + 8 > 80) {
      oy = 80 - 8 + cameraY;
      icn->set_y(oy - cameraY);
      vy = 0;
      icn->set_rotation_angle(0);
      onGround = true;
      return;
    }
  }
  if (loadedData.size() == 0)
    return;

  bn::fixed iconTop = icn->y() - 8 - vy + cameraY;
  bn::fixed iconBottom = icn->y() + 8 - vy + cameraY;
  bn::fixed iconLeft = icn->x() - 8 + 2.75;
  bn::fixed iconRight = icn->x() + 8 + 2.75;
  for (int i = 0; i < hitboxData.size(); i++) {
    bn::fixed objX = getObjX(*hitboxData[i]);
    bn::fixed objY = getObjY(*hitboxData[i]);
    switch (hitboxData[i]->id) {
    case BLOCK:
    case HALF_BLOCK:
    case DETAILED_BLOCK_PILLAR:
    case DETAILED_BLOCK_SIDE:
    case DETAILED_BLOCK_CORNER:
    case DETAILED_BLOCK_END:
      if (iconBottom >= objY - 8 && iconBottom <= objY - 2 &&
          iconRight >= objX - 8 && iconLeft <= objX + 8 && vy < 0) {
        oy = objY - 16;
        icn->set_y(oy - cameraY);
        vy = 0;
        icn->set_rotation_angle(0);
        onGround = true;
        return;
      } else if ((gameMode == SHIP || gameMode == UFO) && vy > 0) {
        if (hitboxData[i]->id != HALF_BLOCK) {
          if (iconTop <= objY + 8 && iconTop >= objY + 2 &&
              iconRight >= objX - 8 && iconLeft <= objX + 8) {
            oy = objY + 16;
            icn->set_y(oy - cameraY);
            vy = 0;
            icn->set_rotation_angle(0);
            underCeiling = true;
            return;
          }
        } else {
          if (iconTop <= objY && iconTop >= objY - 8 + 2 &&
              iconRight >= objX - 8 && iconLeft <= objX + 8) {
            oy = objY + 16;
            icn->set_y(oy - cameraY);
            vy = 0;
            icn->set_rotation_angle(0);
            underCeiling = true;
            return;
          }
        }
      }
      break;
    case DETAILED_BLOCK_PILLAR_TRIPLE:
      if (iconBottom >= objY - 8 - 16 && iconBottom <= objY - 2 - 16 &&
          iconRight >= objX - 8 && iconLeft <= objX + 8 && vy < 0) {
        oy = objY - 16 - 16;
        icn->set_y(oy - cameraY);
        vy = 0;
        icn->set_rotation_angle(0);
        onGround = true;
        return;
      } else if ((gameMode == SHIP || gameMode == UFO) && vy > 0) {
        if (iconTop <= objY + 8 + 16 && iconTop >= objY + 2 + 16 &&
            iconRight >= objX - 8 && iconLeft <= objX + 8) {
          oy = objY + 32;
          icn->set_y(oy - cameraY);
          vy = 0;
          icn->set_rotation_angle(0);
          underCeiling = true;
          return;
        }
      }
      break;
    case DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED:
      if (iconBottom >= objY - 8 && iconBottom <= objY - 2 &&
          iconRight >= objX - 8 - 16 && iconLeft <= objX + 8 + 16 && vy < 0) {
        oy = objY - 16;
        icn->set_y(oy - cameraY);
        vy = 0;
        icn->set_rotation_angle(0);
        onGround = true;
        return;
      } else if ((gameMode == SHIP || gameMode == UFO) && vy > 0) {
        if (iconTop <= objY + 8 && iconTop >= objY + 2 &&
            iconRight >= objX - 8 - 16 && iconLeft <= objX + 8 + 16) {
          oy = objY + 16;
          icn->set_y(oy - cameraY);
          vy = 0;
          icn->set_rotation_angle(0);
          underCeiling = true;
          return;
        }
      }
      break;
    default:
      break;
    }
  }
}

void handleClick() {
  if (bn::keypad::a_held()) {
    if (clicking == false)
      wasClicking = false;
    else
      wasClicking = true;
    clicking = true;
  } else {
    if (clicking)
      wasClicking = true;
    else
      wasClicking = false;
    clicking = false;
  }
  switch (gameMode) {
  case CUBE:
    if (clicking) {
      if (onGround)
        vy = 5.5;
    }
    if (vy > -5.5)
      vy -= GRAVITY;
    oy -= vy;
    break;
  case SHIP:
    if (clicking) {
      // if (!wasClicking) vy /= 2;
      if (vy > SHIP_VEL_LIMIT_UP)
        vy = SHIP_VEL_LIMIT_UP;
      else if (vy < -SHIP_VEL_LIMIT_UP)
        vy = -SHIP_VEL_LIMIT_UP;
      else
        vy += 0.25;
    } else {
      if (wasClicking)
        vy /= 1.95;
      if (vy < -SHIP_VEL_LIMIT_DOWN)
        vy = -SHIP_VEL_LIMIT_DOWN;
      else if (vy > SHIP_VEL_LIMIT_DOWN)
        vy = SHIP_VEL_LIMIT_DOWN;
      else
        vy -= 0.125;
    }
    oy -= vy;
    break;
  default:
    break;
  }
}

void reset() {
  cameraX = 0;
  cameraY = 0;
  rotAngle = 0;
  targetCameraY = -32;
  partToLoad = 0;
  loadNextPart = true;
  data.clear();
  loadedData.clear();
  hitboxData.clear();
  readLevelData();
  ground.clear();
  makeGround();
  if (bn::music::playing())
    bn::music::stop();
  bn::music_items::stereomadness.play();
  icn->set_x(-120 / 3);
  oy = GROUND_LEVEL - 8;
  icn->set_y(oy - cameraY);
  vy = 0;
  gameMode = CUBE;

  dead = false;
  deadFrames = 0;
  icn->set_visible(true);
}

bool handleDeath() {
  if (!dead)
    return false;
  if (deadFrames <= 60 * 1) {
    deadFrames += 1;
    bn::core::update();
    return true;
  } else {
    reset();
    return false;
  }
}

void rotateIcon() {
  switch (gameMode) {
  case CUBE:
    if (onGround)
      return;
    if (rotAngle - ROT_SPEED < 0)
      rotAngle += -ROT_SPEED + 360;
    else
      rotAngle -= ROT_SPEED;
    break;
  case SHIP:
    if (onGround || underCeiling)
      return;
    rotAngle = vy * 7.5;
    if (rotAngle < 0)
      rotAngle += 360;
    else if (rotAngle > 360)
      rotAngle -= 360;
  default:
    break;
  }
  icn->set_rotation_angle(rotAngle);
}

void changeGameModeDBG() {
  if (bn::keypad::l_pressed()) {
    if (gameMode == CUBE) {
      gameMode = SHIP;
      if (oy < -32)
        targetCameraY = oy - 80 + 8;
      else
        targetCameraY = -32;
    } else {
      gameMode = CUBE;
    }
  }
}

void handleGameModeIcon() {
  switch (gameMode) {
  case SHIP:
    icn = bn::sprite_items::ship.create_sprite(-120 / 3, oy - 8 - cameraY);
    break;
  default:
    icn = bn::sprite_items::icon.create_sprite(-120 / 3, oy - 8 - cameraY);
    break;
  }
}
