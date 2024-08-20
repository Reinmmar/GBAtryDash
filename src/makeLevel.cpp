#include "build_level.h"

bn::vector<LevelData, 200> data;
int partToLoad = 0;
bool loadNextPart = true;

void placeObject(int id, bn::fixed x, bn::fixed y, bool flipX, bool flipY,
                 int rot) {
  LevelData g(id, x, y, flipX, flipY, rot);
  data.push_back(g);
}
void makeLevel1() {
  placeObject(SPIKE, 17, 0);

  placeObject(SPIKE_SHORT, 32, 0);
  placeObject(SPIKE, 33, 0);

  placeObject(SPIKE, 48, 0);
  placeObject(SPIKE, 49, 0);
  placeObject(SPIKE_DECO, 52, 0);
  placeObject(SPIKE_DECO, 56, 0);
  placeObject(BLOCK, 50, 0);
  placeObject(DECO_STICK, 50, 1);
  placeObject(GROUND_SPIKES, 51, 0);
  placeObject(GROUND_SPIKES, 52, 0);
  placeObject(GROUND_SPIKES, 53, 0);
  placeObject(DECO_STICK, 54, 2);
  placeObject(DETAILED_BLOCK_PILLAR, 54, 0);
  placeObject(BLOCK, 54, 1);
  placeObject(GROUND_SPIKES, 55, 0);
  placeObject(GROUND_SPIKES, 56, 0);
  placeObject(GROUND_SPIKES, 57, 0);
  placeObject(DETAILED_BLOCK_PILLAR, 58, 0);
  placeObject(DETAILED_BLOCK_PILLAR, 58, 1);
  placeObject(DECO_STICK, 58, 3);
  placeObject(BLOCK, 58, 2);

  placeObject(SPIKE, 79, 0);
  placeObject(SPIKE, 80, 0);

  placeObject(DETAILED_BLOCK_CORNER, 86, 0);
  for (int i = 0; i < 6; i++)
    placeObject(DETAILED_BLOCK_SIDE, 87 + i, 0);
  placeObject(DETAILED_BLOCK_CORNER, 93, 0, true);
  placeObject(SPIKE_DECO, 95, 0);
  for (int i = 0; i < 3; i++)
    placeObject(GROUND_SPIKES, 94 + i, 0);
  placeObject(DETAILED_BLOCK_CORNER, 97, 0);
  for (int i = 0; i < 9; i++)
    placeObject(DETAILED_BLOCK_SIDE, 98 + i, 0);
  placeObject(DETAILED_BLOCK_CORNER, 107, 0, true, false);

  placeObject(SPIKE, 102, 1);
  placeObject(SPIKE_DECO, 109, 0);
  for (int i = 0; i < 3; i++)
    placeObject(GROUND_SPIKES, 108 + i, 0);

  placeObject(DETAILED_BLOCK_SIDE, 111, 0, false, false, 90);
  placeObject(DETAILED_BLOCK_CORNER, 111, 1);
  placeObject(SPIKE, 118, 2);
  for (int i = 0; i < 12; i++) {
    placeObject(DETAILED_BLOCK_CENTER, 112 + i, 0);
    placeObject(DETAILED_BLOCK_SIDE, 112 + i, 1);
  }
  placeObject(DETAILED_BLOCK_SIDE, 124, 0, false, false, -90);
  placeObject(DETAILED_BLOCK_CORNER, 124, 1, true);
  placeObject(SPIKE_DECO, 128, 0);
  placeObject(SPIKE_DECO, 140, 0);
  placeObject(SPIKE_DECO, 143, 0);
  placeObject(SPIKE_DECO, 148, 0);
  for (int i = 0; i < 25; i++)
    placeObject(GROUND_SPIKES, 125 + i, 0);

  for (int i = 0; i < 5; i++) {
    placeObject(HALF_BLOCK, 128 + i * 4, i + 2);
  }

  placeObject(DETAILED_BLOCK_END, 148, 5, false, false, 90);
  for (int i = 0; i < 6; i++) {
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 150 + i * 3, 5);
  }
  placeObject(DETAILED_BLOCK_PILLAR, 167, 5, false, false, -90);
  placeObject(DETAILED_BLOCK_PILLAR, 168, 5, false, false, -90);
  placeObject(DETAILED_BLOCK_CORNER, 169, 5, true);

  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 150, 1);
  for (int i = 0; i < 2; i++) {
    placeObject(DETAILED_BLOCK_PILLAR, 150, i + 3);
  }

  for (int i = 0; i < 4; i++) {
    placeObject(SPIKE, 154 + i, 6);
  }
  for (int i = 0; i < 4; i++) {
    placeObject(SPIKE, 162 + i, 6);
  }
  for (int i = 0; i < 2; i++) {
    placeObject(HALF_BLOCK, 155 + i, 7);
  }
  for (int i = 0; i < 2; i++) {
    placeObject(HALF_BLOCK, 163 + i, 7);
  }
  placeObject(DETAILED_BLOCK_CORNER, 169, 4, false, true);
  for (int i = 0; i < 3; i++) {
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 171 + i * 3, 4);
  }
  placeObject(DETAILED_BLOCK_PILLAR, 179, 4, false, false, -90);
  placeObject(DETAILED_BLOCK_CORNER, 180, 4, true, true);
  for (int i = 0; i < 4; i++) {
    placeObject(HALF_BLOCK, 173 + i, 6);
  }
  for (int i = 0; i < 4; i++) {
    placeObject(SPIKE, 173 + i, 7);
  }
  placeObject(DETAILED_BLOCK_CORNER, 180, 5);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 182, 5);
  placeObject(DETAILED_BLOCK_CORNER, 184, 5, true);
  placeObject(SPIKE, 184, 6);
  placeObject(SPIKE, 185, 4);
  placeObject(DETAILED_BLOCK_PILLAR, 184, 4);
  placeObject(DETAILED_BLOCK_CORNER, 184, 3, false, true);
  for (int i = 0; i < 3; i++) {
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 186 + i * 3, 3);
  }
  placeObject(DETAILED_BLOCK_END, 194, 3, false, false, -90);
  for (int i = 0; i < 4; i++) {
    placeObject(HALF_BLOCK, 197 + i, 3);
  }
  placeObject(SPIKE, 200, 4);
  placeObject(SPIKE_DECO, 196, 0);
  placeObject(SPIKE_DECO, 203, 0);
  placeObject(SPIKE_DECO, 206, 0);
  placeObject(SPIKE_DECO, 213, 0);
  placeObject(SPIKE_DECO, 219, 0);
  placeObject(SPIKE_DECO, 225, 0);
  placeObject(SPIKE_DECO, 232, 0);
  placeObject(SPIKE_DECO, 240, 0);
}
void makeLevel2() {
  for (int i = 0; i < 52; i++) {
    placeObject(GROUND_SPIKES, 191 + i, 0);
  }
  for (int i = 0; i < 7; i++) {
    placeObject(HALF_BLOCK, 202 + i, 2);
  }
  placeObject(SPIKE, 208, 3);
  for (int i = 0; i < 5; i++) {
    placeObject(HALF_BLOCK, 210 + i, 1);
  }
  for (int i = 0; i < 6; i++) {
    placeObject(HALF_BLOCK, 218 + i * 4, i + 2);
  }
  placeObject(SPIKE, 238, 8);
  placeObject(DETAILED_BLOCK_END, 236, 3, false, false, 90);
  for (int i = 0; i < 9; i++) {
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 238 + i * 3, 3);
  }
  placeObject(DETAILED_BLOCK_PILLAR, 264, 3, false, false, -90);
  placeObject(DETAILED_BLOCK_PILLAR, 265, 3, false, false, -90);
  placeObject(DETAILED_BLOCK_END, 266, 3, false, false, -90);
  placeObject(DETAILED_BLOCK_END, 243, 7, false, false, 90);
  placeObject(DETAILED_BLOCK_PILLAR, 244, 7, false, false, -90);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 246, 7);

  placeObject(DETAILED_BLOCK_CORNER, 248, 7, true);
  placeObject(DETAILED_BLOCK_CORNER, 248, 6, false, true);
  for (int i = 0; i < 4; i++) {
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 250 + i * 3, 6);
  }
  placeObject(DETAILED_BLOCK_CORNER, 261, 6, true, true);
  placeObject(DETAILED_BLOCK_CORNER, 261, 7);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 263, 7);
  placeObject(DETAILED_BLOCK_PILLAR, 265, 7, false, false, -90);
  placeObject(DETAILED_BLOCK_END, 266, 7, false, false, -90);
  placeObject(SHIP_PORTAL, 266, 5);

  placeObject(NORMAL_FACE, 280, 4);

  placeObject(DETAILED_BLOCK_END, 301, 7, false, true);
  placeObject(DETAILED_BLOCK_PILLAR, 301, 8);
  placeObject(DETAILED_BLOCK_PILLAR, 301, 9);

  placeObject(DETAILED_BLOCK_END, 314, 0);
  placeObject(DETAILED_BLOCK_END, 314, 9, false, true);
  for (int i = 0; i < 14; i++) {
    placeObject(SPIKE, 315 + i, 9, false, true);
    placeObject(SPIKE, 315 + i, 0);
  }

  placeObject(DETAILED_BLOCK_END, 329, 0);
  placeObject(DETAILED_BLOCK_END, 329, 9, false, true);

  placeObject(DETAILED_BLOCK_PILLAR, 342, 0);
  placeObject(DETAILED_BLOCK_END, 342, 1);
}
void makeLevel2_1() {
  for (int i = 0; i < 4; i++)
    placeObject(SPIKE, 343 + i, 0);

  placeObject(DETAILED_BLOCK_PILLAR, 355, 9);
  placeObject(DETAILED_BLOCK_END, 355, 8, false, true);
  for (int i = 0; i < 4; i++)
    placeObject(SPIKE, 356 + i, 9, false, true);

  placeObject(DETAILED_BLOCK_END, 364, 0);
  placeObject(DETAILED_BLOCK_PILLAR, 370, 0);
  placeObject(DETAILED_BLOCK_END, 370, 1);

  for (int i = 0; i < 5; i++) {
    placeObject(SPIKE, 365 + i, 0);
    placeObject(SPIKE, 371 + i, 0);
  }
  placeObject(DETAILED_BLOCK_PILLAR, 376, 0);
  placeObject(DETAILED_BLOCK_PILLAR, 376, 1);
  placeObject(DETAILED_BLOCK_END, 376, 2);

  for (int i = 0; i < 20; i++) {
    if (i == 6)
      continue;
    placeObject(SPIKE, 384 + i, 9, false, true);
  }

  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 390, 8);
  placeObject(DETAILED_BLOCK_END, 390, 6, false, true);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 404, 9);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 404, 0);
  placeObject(DETAILED_BLOCK_CORNER, 404, 7, false, true);
  placeObject(DETAILED_BLOCK_CORNER, 404, 2);
  placeObject(DETAILED_BLOCK_CORNER, 432, 1, true);
  placeObject(DETAILED_BLOCK_PILLAR, 432, 0);
  for (int i = 0; i < 4; i++) {
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 406 + i * 3, 7);
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 406 + i * 3, 2);
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 420 + i * 3, 1);
  }
  placeObject(DETAILED_BLOCK_PILLAR, 431, 1, false, false, -90);
  placeObject(DETAILED_BLOCK_END, 417, 7, false, false, -90);
  placeObject(DETAILED_BLOCK_END, 417, 2, false, false, -90);
  placeObject(DETAILED_BLOCK_END, 418, 1, false, false, 90);
  placeObject(CUBE_PORTAL, 418, 4.5);

  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 436, 0);
  placeObject(DETAILED_BLOCK_END, 436, 2);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 440, 1);
  placeObject(DETAILED_BLOCK_END, 440, 3);
  placeObject(DETAILED_BLOCK_END, 444, 0);
  placeObject(DETAILED_BLOCK_END, 444, 3, false, true);
  placeObject(DETAILED_BLOCK_END, 444, 4);
  placeObject(DETAILED_BLOCK_END, 448, 4, false, true);
  placeObject(DETAILED_BLOCK_END, 448, 5);
  placeObject(DETAILED_BLOCK_CORNER, 448, 1);
  placeObject(DETAILED_BLOCK_PILLAR, 448, 0);
  for (int i = 0; i < 2; i++) {
    placeObject(DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED, 450 + i * 3, 1);
  }
}
void makeLevel3() {
  placeObject(DETAILED_BLOCK_CORNER, 455, 1, true);
  placeObject(DETAILED_BLOCK_PILLAR, 455, 0);
  for (int i = 0; i < 1; i++) {
    placeObject(SPIKE, 449 + i, 8.5, false, true);
    placeObject(BLOCK, 449 + i, 9.5);
  }

  for (int i = 0; i < 7; i++) {
    placeObject(DETAILED_BLOCK_END, 459 + i * 4, 2 + i);
    placeObject(DETAILED_BLOCK_END, 459 + i * 4, 1 + i, false, true);
  }
  placeObject(HALF_BLOCK, 484, 8);
  placeObject(HALF_BLOCK, 486, 7);
  placeObject(HALF_BLOCK, 487, 7);
  placeObject(HALF_BLOCK, 489, 6);
  placeObject(HALF_BLOCK, 490, 6);
  placeObject(HALF_BLOCK, 492, 5);
  placeObject(HALF_BLOCK, 493, 5);
  placeObject(HALF_BLOCK, 494, 5);
  placeObject(HALF_BLOCK, 498, 4);
  placeObject(HALF_BLOCK, 499, 4);
  placeObject(HALF_BLOCK, 501, 3.5);
  placeObject(HALF_BLOCK, 502, 3.5);
  placeObject(HALF_BLOCK, 503, 3.5);
  placeObject(HALF_BLOCK, 507, 2.5);
  placeObject(HALF_BLOCK, 508, 2.5);
  placeObject(HALF_BLOCK, 509, 2.5);
  placeObject(HALF_BLOCK, 510, 2.5);
  placeObject(HALF_BLOCK, 512, 2);
  placeObject(HALF_BLOCK, 514, 1);
  placeObject(HALF_BLOCK, 516, 0);

  placeObject(SPIKE_DECO, 434, 0);
  placeObject(SPIKE_DECO, 438, 0);
  placeObject(SPIKE_DECO, 442, 0);
  placeObject(SPIKE_DECO, 446, 0);
  placeObject(SPIKE_DECO, 458, 0);
  placeObject(SPIKE_DECO, 465, 0);
  placeObject(SPIKE_DECO, 495, 0);
  placeObject(SPIKE_DECO, 505, 0);
  placeObject(SPIKE_DECO, 513, 0);

  for (int i = 0; i < 84; i++) {
    if (i == 3 || i == 7 || i == 11 || (i >= 15 && i <= 22))
      continue;
    placeObject(GROUND_SPIKES, 433 + i, 0);
  }
}
void makeLevel4() {
  placeObject(SPIKE, 523, 0);
  placeObject(SPIKE, 524, 0);
  placeObject(BLOCK, 525, 0);
  placeObject(HALF_BLOCK, 528, 1);
  placeObject(HALF_BLOCK, 529, 1);
  placeObject(BLOCK, 531, 0);
  placeObject(BLOCK, 532, 0);
  placeObject(BLOCK, 533, 0);
  placeObject(HALF_BLOCK, 536, 1);
  placeObject(HALF_BLOCK, 537, 1);
  placeObject(HALF_BLOCK, 540, 2);
  placeObject(HALF_BLOCK, 541, 2);
  placeObject(BLOCK, 543, 0);
  placeObject(BLOCK, 544, 0);
  placeObject(BLOCK, 545, 0);
  placeObject(SPIKE, 546, 0);
  for (int i = 0; i < 2; i++) {
    placeObject(SPIKE, 554 + i, 0);
    placeObject(SPIKE, 554 + i, 4, false, true);
    placeObject(BLOCK, 554 + i, 5);
  }
  placeObject(SPIKE, 562.1, 0);
  placeObject(SPIKE, 562.1, 4, false, true);
  placeObject(BLOCK, 562.1, 5);
  placeObject(SPIKE, 562.9, 0);
  placeObject(SPIKE, 562.9, 4, false, true);
  placeObject(BLOCK, 562.9, 5);
  placeObject(SPIKE, 563.7, 0);
  placeObject(SPIKE, 563.7, 4, false, true);
  placeObject(BLOCK, 563.7, 5);
  placeObject(SPIKE, 570, 0);
  placeObject(SPIKE, 570, 4, false, true);
  placeObject(BLOCK, 570, 5);
  placeObject(SPIKE, 577.3, 0);
  placeObject(SPIKE, 577.3, 4, false, true);
  placeObject(BLOCK, 577.3, 5);

  placeObject(SPIKE_DECO, 528, 0);
  placeObject(SPIKE_DECO, 539, 0);
  for (int i = 0; i < 17; i++) {
    if (i == 5 || i == 6 || i == 7)
      continue;
    placeObject(GROUND_SPIKES, 526 + i, 0);
  }
}
void makeLevel5() {
  placeObject(SPIKE, 586, 0);
  placeObject(SPIKE, 587, 0);
  placeObject(BLOCK, 588, 0);
  placeObject(BLOCK, 592, 1);
  placeObject(BLOCK, 596, 2);
  placeObject(BLOCK, 600, 3);
  placeObject(HALF_BLOCK, 601, 3);
  placeObject(HALF_BLOCK, 603, 2);
  placeObject(HALF_BLOCK, 605, 1);
  placeObject(HALF_BLOCK, 607, 0);
  placeObject(DETAILED_BLOCK_PILLAR, 592, 0);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 596, 0);
  placeObject(DETAILED_BLOCK_PILLAR_TRIPLE, 600, 1);
  placeObject(SPIKE_DECO, 590, 0);
  placeObject(SPIKE_DECO, 598, 0);
  placeObject(SPIKE_DECO, 603, 0);

  placeObject(SPIKE, 613, 0);
  placeObject(SPIKE, 614, 0);
  for (int i = 0; i < 4; i++) {
    placeObject(SPIKE, 621 + i, 1, false, true);
    placeObject(BLOCK, 621 + i, 2);
  }
  placeObject(SPIKE, 629, 0);
  placeObject(BLOCK, 630, 0);
  placeObject(DECO_STICK_LARGE, 630, 1);

  for (int i = 0; i < 4; i++) {
    placeObject(HALF_BLOCK, 639 + i, 0);
  }
  for (int i = 0; i < 3; i++) {
    placeObject(HALF_BLOCK, 646 + i * 4, 1 + i);
    placeObject(HALF_BLOCK, 658 + i, 4);
    placeObject(BLOCK, 662 + i * 2, 3 - i);
    placeObject(BLOCK, 662 + i * 2, 6 - i);
  }
  placeObject(BLOCK, 668.5, 0);
  placeObject(BLOCK, 668.5, 3.5);
  placeObject(SPIKE_SHORT, 668.5, 4.5);
  placeObject(BLOCK, 668.5, 0);

  placeObject(HALF_BLOCK, 672.5, 1);
  placeObject(HALF_BLOCK, 674.9, 1);
  placeObject(SPIKE, 674.9, 2);
  placeObject(HALF_BLOCK, 677.5, 1);

  placeObject(HALF_BLOCK, 681, 2);
  placeObject(HALF_BLOCK, 682, 2);
  placeObject(HALF_BLOCK, 683, 2);
  placeObject(HALF_BLOCK, 685, 1);
  placeObject(HALF_BLOCK, 687, 0);
  placeObject(HALF_BLOCK, 688, 0);
  placeObject(HALF_BLOCK, 689, 0);
  placeObject(SPIKE, 690, 0);
  placeObject(SPIKE, 691, 0);

  for (int i = 0; i < 3; i++) {
    placeObject(SPIKE, 698.1 + i * 0.8, 0);
    placeObject(SPIKE, 698.1 + i * 0.8, 3, false, true);
    placeObject(BLOCK, 698.1 + i * 0.8, 4);
  }

  for (int i = 0; i < 51; i++)
    placeObject(GROUND_SPIKES, 639 + i, 0);

  for (int i = 0; i < 19; i++) {
    switch (i) {
    case 3:
    case 7:
    case 11:
      continue;
    default:
      break;
    }
    placeObject(GROUND_SPIKES, 589 + i, 0);
  }
}
void makeLevel6() {
  placeObject(BLOCK, 710, 0);
  for (int i = 0; i < 53; i++) {
    placeObject(GROUND_SPIKES, 711 + i, 0);
  }
  placeObject(HALF_BLOCK, 711, 0);
  placeObject(HALF_BLOCK, 712, 0);
  placeObject(HALF_BLOCK, 716.5, 0);
  placeObject(HALF_BLOCK, 721, 0);
  placeObject(HALF_BLOCK, 722, 0);
  placeObject(BLOCK, 723, 0);
  placeObject(BLOCK, 724, 0);
  placeObject(BLOCK, 724, 1);
  placeObject(HALF_BLOCK, 725, 1);
  placeObject(HALF_BLOCK, 726, 1);
  placeObject(HALF_BLOCK, 730, 2);
  placeObject(HALF_BLOCK, 732, 1);
  placeObject(HALF_BLOCK, 734, 0);
  placeObject(HALF_BLOCK, 735, 0);
  placeObject(HALF_BLOCK, 736, 0);
  placeObject(HALF_BLOCK, 740, 1);
}
void makeLevel7() {
  placeObject(DECO_STICK, 740, 2);
  placeObject(HALF_BLOCK, 742, 1);
  placeObject(SPIKE, 742, 2);
  placeObject(HALF_BLOCK, 744, 1);
  placeObject(DECO_STICK, 744, 2);
  placeObject(HALF_BLOCK, 745, 1);
  placeObject(HALF_BLOCK, 746, 1);
  placeObject(HALF_BLOCK, 747, 1);
  placeObject(DECO_STICK, 747, 2);
  placeObject(HALF_BLOCK, 749.5, 1);
  placeObject(SPIKE, 749.5, 2);
  placeObject(HALF_BLOCK, 752, 1);
  placeObject(HALF_BLOCK, 756, 2);
  placeObject(DECO_STICK, 756, 3);
  placeObject(HALF_BLOCK, 757, 2);
  placeObject(HALF_BLOCK, 758, 2);
  placeObject(SPIKE, 758, 3);
  placeObject(HALF_BLOCK, 760, 1);
  placeObject(HALF_BLOCK, 761, 1);
  placeObject(HALF_BLOCK, 762, 1);
  placeObject(BLOCK, 764, 0);
  placeObject(BLOCK, 764, 1);
  placeObject(BLOCK, 764, 2);
  placeObject(BLOCK, 764, 7);
  placeObject(BLOCK, 764, 8);
  placeObject(BLOCK, 764, 9);
  placeObject(DECO_STICK, 765, 1, false, false, 90);
  placeObject(DECO_STICK, 765, 2, false, false, 90);
  placeObject(DECO_STICK, 765, 8, false, false, 90);
  placeObject(DECO_STICK, 765, 7, false, false, 90);
  placeObject(SHIP_PORTAL, 764, 4.5);
}
void makeLevel8() {
  placeObject(BLOCK, 777, 0);
  placeObject(BLOCK, 777, 9);
  placeObject(DECO_STICK, 777, 1);
  placeObject(DECO_STICK, 777, 8, false, true);
  placeObject(BLOCK, 778, 1);
  placeObject(BLOCK, 778, 8);
  for (int i = 0; i < 6; i++) {
    placeObject(BLOCK, 779 + i, 2);
    placeObject(BLOCK, 779 + i, 7);
  }
  placeObject(BLOCK, 785, 1);
  placeObject(BLOCK, 785, 8);
  placeObject(BLOCK, 786, 0);
  placeObject(BLOCK, 786, 9);
  placeObject(DECO_STICK, 786, 8, false, true);
  placeObject(DECO_STICK, 786, 1);

  for (int i = 0; i < 8; i++) {
    placeObject(GROUND_SPIKES, 787 + i, 0);
    if (i < 6)
      placeObject(GROUND_SPIKES, 787 + i, 9, false, true);
  }
}
void makeLevel8_1() {
  placeObject(BLOCK, 795, 0);
  placeObject(BLOCK, 796, 1);
  placeObject(BLOCK, 796, 8);
  for (int i = 0; i < 6; i++) {
    placeObject(BLOCK, 797 + i, 2);
    placeObject(BLOCK, 797 + i, 7);
  }
  placeObject(BLOCK, 803, 8);
  placeObject(BLOCK, 803, 1);
  placeObject(BLOCK, 804, 9);
  placeObject(BLOCK, 804, 0);
}
void makeLevel9() {
  for (int i = 0; i < 22; i++) {
    // if (i != 7 && i != 8 && i != 9)
    //   placeObject(GROUND_SPIKES, 805 + i, 0);
    // placeObject(GROUND_SPIKES, 805 + i, 9, false, true);
  }
  placeObject(BLOCK, 812, 0);
  placeObject(BLOCK, 812, 1);
  placeObject(BLOCK, 812, 2);
  placeObject(BLOCK, 812, 3);
  placeObject(BLOCK, 813, 3);
  placeObject(BLOCK, 814, 3);
  placeObject(BLOCK, 814, 2);
  placeObject(BLOCK, 814, 1);
  placeObject(BLOCK, 814, 0);
  placeObject(BLOCK, 827, 9);
  placeObject(BLOCK, 827, 8);
  placeObject(BLOCK, 827, 7);
  placeObject(BLOCK, 827, 6);
  placeObject(BLOCK, 828, 6);
  placeObject(BLOCK, 829, 6);
  placeObject(BLOCK, 829, 7);
  placeObject(BLOCK, 829, 8);
  placeObject(BLOCK, 829, 9);
  placeObject(GROUND_SPIKES, 827, 0);
  placeObject(GROUND_SPIKES, 828, 0);
  placeObject(GROUND_SPIKES, 829, 0);

  for (int i = 0; i < 14; i++) {
    // placeObject(GROUND_SPIKES, 830 + i, 0);
    // placeObject(GROUND_SPIKES, 830 + i, 9, false, true);
  }
}
void makeLevel10() {
  for (int i = 0; i < 6; i++) {
    placeObject(BLOCK, 844 + i, 0);
    placeObject(SPIKE, 844 + i, 1);
    placeObject(BLOCK, 844 + i, 9);
    placeObject(SPIKE, 844 + i, 8, false, true);
  }
  for (int i = 0; i < 5; i++) {
    // placeObject(GROUND_SPIKES, 850 + i, 0);
    // placeObject(GROUND_SPIKES, 850 + i, 9, false, true);
  }
}
void makeLevel11() {
  placeObject(BLOCK, 855, 9);
  placeObject(BLOCK, 855, 0);
  placeObject(BLOCK, 860, 9);
  placeObject(BLOCK, 860, 0);
  for (int i = 0; i < 6; i++) {
    if (i == 0 || i == 5) {
      placeObject(BLOCK, 855 + i, 8);
      placeObject(BLOCK, 855 + i, 1);
    }
    placeObject(SPIKE, 855 + i, 2);
    placeObject(SPIKE, 855 + i, 7, false, true);

    // placeObject(GROUND_SPIKES, 861 + i, 0);
    // placeObject(GROUND_SPIKES, 861 + i, 9, false, true);
  }
}
void makeLevel11_1() {
  placeObject(BLOCK, 867, 1);
  placeObject(BLOCK, 867, 0);
  placeObject(BLOCK, 867, 9);
  placeObject(BLOCK, 867, 8);
  placeObject(DECO_STICK, 866, 1, false, false, 270);
  placeObject(DECO_STICK, 866, 2, false, false, 270);
  placeObject(DECO_STICK, 866, 8, false, false, 270);
  placeObject(DECO_STICK, 866, 7, false, false, 270);
}
void makeLevel12() {
  for (int i = 0; i < 12; i++) {
    placeObject(BLOCK, 867 + i, 2);
    placeObject(BLOCK, 867 + i, 7);
  }
  placeObject(BLOCK, 878, 9);
  placeObject(BLOCK, 878, 8);
  placeObject(BLOCK, 878, 0);
  placeObject(BLOCK, 878, 1);
  placeObject(DECO_STICK, 879, 1, false, false, 90);
  placeObject(DECO_STICK, 879, 2, false, false, 90);
  placeObject(DECO_STICK, 879, 8, false, false, 90);
  placeObject(DECO_STICK, 879, 7, false, false, 90);
}
FunctionArray makeLevelList[] = {
    makeLevel1,  makeLevel2,    makeLevel2_1, makeLevel3,
    makeLevel4,  makeLevel5,    makeLevel6,   makeLevel7,
    makeLevel8,  makeLevel8_1,  makeLevel9,   makeLevel10,
    makeLevel11, makeLevel11_1, makeLevel12,  NULL};