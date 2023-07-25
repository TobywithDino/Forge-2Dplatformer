#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/gb.h"
#include "headers/allSprite.h"

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
};