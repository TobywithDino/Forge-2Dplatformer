#pragma once
#include "headers/gameLoop/gameLoop.h"
#include "headers/crawler.h"
#include "headers/ploder.h"
#include "headers/player.h"
#include "headers/button.h"

class LevelSpawner{
public:
    static void update();
private:
    static void loadLevel();
    static void spawnLevelEntities();
    static void spawnPlayer(vector2 pos);
    static void spawnEnemy(vector2 pos, int ratio[]);
    static void spawnWeaponBox();
    static vector2 playerSpawnPos;
    static vector<vector2> enemySpawnPos;
    static Uint64 nextSpawnTick;
    static Uint64 spawnGapTicks;
    static int ratio[ENEMY_END];
};