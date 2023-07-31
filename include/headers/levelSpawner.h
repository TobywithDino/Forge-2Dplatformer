#pragma once
#include "headers/gameLoop/gameLoop.h"
#include "headers/crawler.h"
#include "headers/ploder.h"
#include "headers/player.h"
#include "headers/staticEntity.h"

class LevelSpawner{
public:
    static void update();
private:
    static void loadLevel();
    static void spawnLevelEntities();
    static void spawnPlayer(vector2 pos);
    static void spawnEnemy(vector2 pos, int ratio[]);
    static void clearEnemy();
    static void clearLevel();
    static vector2 playerSpawnPos;
    static vector2 enemySpawnPos;
    static Uint64 nextSpawnTick;
    static Uint64 spawnGapTicks;
    static int ratio[ENEMY_END];
};