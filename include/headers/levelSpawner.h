#pragma once
#include "headers/allSprite.h"
#include "headers/gameLoop/gameLoop.h"

class LevelSpawner{
public:
    static void update(int levelIndex);
private:
    static void spawnLevel();
    static vector2 playerSpawnPos;
    static Uint64 nextSpawnTick;
    static Uint64 spawnGapTicks;
};