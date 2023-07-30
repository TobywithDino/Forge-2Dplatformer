#pragma once
#include "headers/entity.h"

class AllSprite{
public:
    static int init();
    static void handleEvent(SDL_Event e);
    static void update();
    static void render();
    static void addEnemy(Entity* e);
    static void addPlayer(Entity* e);
    static void addLevelEntity(Entity* e);
    static bool isEnemyFull();
private:
    static Entity* enemyEntities[gb::maxEnemyEntities];
    static Entity* levelEntities[gb::maxLevelEntities];
    static Entity* player;
    static int enemyIndex;
    static int levelIndex;

    static Entity** entities[gb::maxEntities];
};