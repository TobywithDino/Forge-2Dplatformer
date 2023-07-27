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

    /* about to dump them
    static void collision();
    static bool collided(Entity *a, Entity *b);
    static bool onGroundAgain(Entity tmp_a, Entity tmp_b);
    static void blockH(Entity *a, Entity *b);
    static void blockV(Entity *a, Entity *b);
    */
    static void loadLevelEntities(int index);

    static Entity* enemyEntities[gb::maxEnemyEntities];
    static Entity* levelEntities[gb::maxLevelEntities];
    static Entity* player;

    static Entity** entities[gb::maxEntities];
};