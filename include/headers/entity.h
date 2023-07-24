#pragma once
#include "headers/vector2.h"
#include "SDL2/SDL.h"

class Entity{
public:
    Entity();
    void update();
    void render();
private:
    vector2 pos;
    vector2 vel;
    SDL_Texture* tex;
};