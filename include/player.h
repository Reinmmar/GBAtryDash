#include "includes.h"

#define SHIP_VEL_LIMIT_UP 3.8
#define SHIP_VEL_LIMIT_DOWN 3
#define GRAVITY 0.4
#define GROUND_LEVEL 160 / 2 - 32
#define ROT_SPEED 7

extern int gameMode;
extern bn::fixed rotAngle;
extern bool dead;
extern bool onGround;
extern bool underCeiling;
extern bool clicking;
extern bool wasClicking;
extern bn::fixed deadFrames;
extern bn::fixed oy;
extern bn::fixed vy;
extern bn::fixed cameraY;
extern bn::fixed targetCameraY;
extern bn::optional<bn::sprite_ptr> icn;

void makeGround();
void handleLand();
void handleClick();
void reset();
bool handleDeath();
void rotateIcon();
void changeGameModeDBG();
void handleGameModeIcon();
