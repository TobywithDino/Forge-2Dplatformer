#pragma once
#include "headers/player.h"
#include "headers/staticEntity.h"

class AllSprite{
public:
    static int init();
    static void handleEvent(SDL_Event e);
    static void update();
    static void render();
private:
    static void checkCollide();
    static void loadLevelEntities(int index);

    static const int maxEnemyEntities = 30;
    static const int maxLevelEntities = 20;
    static const int maxEntities = maxEnemyEntities + maxLevelEntities + 1;
    static Entity* enemyEntities[maxEnemyEntities];
    static Entity* levelEntities[maxLevelEntities];
    static Entity* player;

    static Entity** entities[maxEntities];
};