#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/gb.h"
#include "headers/player.h"

#include <vector>
using namespace std;

class Game{
public:
    Game();
    int init();
private:
    void handleEvent();
    void update();
    void render();

    vector<MovableEntity*> entities;
    MovableEntity* player;
};