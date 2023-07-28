#pragma once
#include "headers/player.h"
#include "headers/staticEntity.h"
#include "headers/enemy.h"

class AllSprite{
public:
    static int init();
    static void handleEvent(SDL_Event e);
    static void update();
    static void render();

    static void spawnLevel(int levelIndex);
    static void spawnEnemy(EnemyType type, vector2 pos);
    static void spawnPlayer(vector2 pos);
    static void clearEnemy();
private:
    static Entity* enemyEntities[gb::maxEnemyEntities];
    static int enemyIndex;
    static Entity* levelEntities[gb::maxLevelEntities];
    static Entity* player;

    static Entity** entities[gb::maxEntities];
};