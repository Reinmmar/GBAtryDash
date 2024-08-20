#include "includes.h"

enum GameModes { CUBE, SHIP, BALL, UFO, WAVE, ROBOT, SPIDER };
#define LEVEL_SPEED 2.75

extern bn::fixed cameraX;
extern bn::fixed cameraY;
extern bn::fixed deadFrames;
extern bn::fixed vy;
extern bn::fixed oy;
extern bn::vector<bn::sprite_ptr, 5> ground;
extern int gameMode;
extern void handleLand(int);
extern void handlePortals(int);
extern bool dead;

void removeSprite(int&);
void moveLevel();
void readLevelData();
bool dieCheck();