/*
 * Copyright (c) 2020-2023 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "build_level.h"
#include "level.h"
#include "player.h"

#define SPEED 0.25
bn::vector<bn::sprite_ptr, 5> ground;
bn::fixed deadFrames = 0;
bn::fixed vy = 0;
bn::fixed oy = GROUND_LEVEL - 8;
bn::fixed cameraX = 0;
bn::fixed cameraY = 0;
bn::fixed targetCameraY = -32;
bn::optional<bn::sprite_ptr> icn;
bool dead = false;
bool onGround = true;
bool underCeiling = false;
bool wasClicking = false;
bool clicking = false;

void moveGround() {
  for (int i = 0; i < ground.size(); i++) {
    if (ground[i].x() - 84 < -240) {
      ground[i].set_x(ground[i].x() + 64 * 5);
    }
    ground[i].set_x(ground[i].x() - LEVEL_SPEED);
    ground[i].set_y(GROUND_LEVEL + 32 - cameraY);
  }
}

void makeGround() {
  for (int i = 0; i < 5; i++) {
    ground.emplace_back(bn::sprite_items::gnd_square.create_sprite(
      -240 / 2 + 32 + i * 64, 160 / 2));
    ground[ground.size() - 1].set_z_order(-2);
  }
}

void setPortalCamera() {
  if (oy + 8 < -32)
    targetCameraY = oy + 8;
  else
    targetCameraY = -32;
}

void moveCamera() {
  cameraX += LEVEL_SPEED;
  if (gameMode == CUBE || gameMode == ROBOT) {
    if (icn->y() < (-160 / 4)) {
      cameraY -= LEVEL_SPEED;
      // targetCameraY = cameraY;
    }
    else if (icn->y() > (160 / 4)) {
      cameraY += LEVEL_SPEED;
      // targetCameraY = cameraY;
    }
    return;
  }
  if (cameraY - LEVEL_SPEED > targetCameraY)
    cameraY -= LEVEL_SPEED;
  else if (cameraY + LEVEL_SPEED < targetCameraY)
    cameraY += LEVEL_SPEED;
  else
    cameraY = targetCameraY;
}

int main() {
  bn::core::init();
  bn::regular_bg_ptr bg_square = bn::regular_bg_items::square.create_bg(0, -48);
  makeGround();
  icn = bn::sprite_items::icon.create_sprite(-120 / 3, GROUND_LEVEL - 8);
  bn::music_items::stereomadness.play();

  while (true) {
    if (loadNextPart && makeLevelList[partToLoad] != NULL) {
      makeLevelList[partToLoad]();
      partToLoad++;
      loadNextPart = false;
    }

    if (handleDeath())
      continue;
    handleGameModeIcon();
    icn->set_z_order(-1);

    readLevelData();

    changeGameModeDBG();

    moveCamera();

    handleClick();
    if (bn::keypad::r_pressed()) {
      reset();
    }
    icn->set_y(oy - cameraY);

    handleLand();

    rotateIcon();
    if (dieCheck()) {
      icn->set_visible(false);
      bn::music::stop();
      bn::sound_items::explode_11.play();
      dead = true;
      deadFrames = 0;
    }
    bg_square.set_x(bg_square.x() - SPEED);
    bg_square.set_y(-cameraY / 4 - 48);

    moveLevel();
    moveGround();

    bn::core::update();
  }
}
