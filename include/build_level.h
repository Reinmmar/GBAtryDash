#include "includes.h"

enum Types {
  NONE,
  SOLID,
  KILL,
  PORTAL
};

class LevelData {
public:
  int id;
  bn::fixed x;
  bn::fixed y;
  bn::fixed rot;
  bool flipX;
  bool flipY;
  int type;
  int up;
  int right;
  int down;
  int left;
  bn::optional<bn::sprite_ptr> sprite;
  LevelData(int obj, bn::fixed xp, bn::fixed yp, bn::fixed r, bool fx, bool fy, int u, int ri, int d, int l);
};

extern bn::vector<LevelData, 200> data;
extern bn::vector<LevelData*, 100> loadedData;
extern bn::vector<LevelData*, 16> hitboxData;
extern int partToLoad;
extern bool loadNextPart;

typedef void (*FunctionArray) ();
extern FunctionArray makeLevelList[];

void placeObject(int, bn::fixed, bn::fixed, bool = false, bool = false,
  int = 0);
bn::fixed getObjX(LevelData);
bn::fixed getObjY(LevelData);

typedef enum {
  BLOCK,
  DETAILED_BLOCK_PILLAR,
  DETAILED_BLOCK_PILLAR_TRIPLE,
  DETAILED_BLOCK_PILLAR_TRIPLE_ROTATED,
  DETAILED_BLOCK_SIDE,
  DETAILED_BLOCK_CORNER,
  DETAILED_BLOCK_CORNER_INVERTED,
  DETAILED_BLOCK_CENTER,
  DETAILED_BLOCK_END,
  HALF_BLOCK,
  SPIKE,
  SPIKE_SHORT,
  GROUND_SPIKES,
  SPIKE_DECO,
  DECO_STICK_LARGE,
  DECO_STICK,
  NORMAL_FACE,
  CUBE_PORTAL,
  SHIP_PORTAL,
} Objects;