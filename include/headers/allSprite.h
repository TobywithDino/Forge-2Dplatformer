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
    static void loadGameEntities();
private:
    static void loadLevelEntities(int index);

    static Entity* enemyEntities[gb::maxEnemyEntities];
    static Entity* levelEntities[gb::maxLevelEntities];
    static Entity* player;

    static Entity** entities[gb::maxEntities];
};