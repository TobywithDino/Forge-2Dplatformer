#pragma once
#include "headers/player.h"

class AllSprite{
public:
    static int init();
    static void handleEvent(SDL_Event e);
    static void update();
    static void render();
private:
    static void checkCollide();
    bool checkHorizontal();
    bool checkVertical();

    static const int maxEnemies = 1;
    static Entity* enemies[maxEnemies];
    static Entity* player;
};