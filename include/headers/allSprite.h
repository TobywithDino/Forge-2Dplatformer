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

    static const int maxEnemyEntites = 1;
    static const int maxLevelEntities = 20;
    static const int maxEntities = 50;
    static Entity* enemyEntities[maxEnemyEntites];
    static Entity* levelEntities[maxLevelEntities];
    static Entity* player;

    static Entity** entities[maxEntities];
};