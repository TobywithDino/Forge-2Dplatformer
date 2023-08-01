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
    static void addProjt(Entity* e);
    static void clearEnemy();
    static void clearLevel();
    static void clearProjt();
    static void clearPlayer();
private:
    static bool isEnemyFull();
    static bool isProjtFull();
    static Entity* enemyEntities[gb::maxEnemyEntities];
    static Entity* levelEntities[gb::maxLevelEntities];
    static Entity* projtEntities[gb::maxProjtEntities];
    static Entity* player;
    static int enemyIndex;
    static int levelIndex;
    static int projtIndex;

    static Entity** entities[gb::maxEntities];
};