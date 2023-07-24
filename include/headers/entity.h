#pragma once
#include "SDL2/SDL.h"
#include "headers/texture.h"
#include "headers/vector2.h"

class Entity{
public:
    Entity();
    Entity(vector2 pos, vector2 vel, TextureType type);
    Entity(vector2 pos, vector2 vel, TextureType type, vector2 size);
    void handleEvent();
    void update();
    void render();
private:
    SDL_Texture* tex;
    const double gravity = 2000;
protected:
    void setPos(vector2 p) {pos = p;}
    void setVel(vector2 v) {vel = v;}
    
    vector2 pos;
    vector2 vel;
    vector2 size;
};