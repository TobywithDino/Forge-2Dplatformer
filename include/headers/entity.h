#pragma once
#include "SDL2/SDL.h"
#include "headers/texture.h"
#include "headers/vector2.h"

class Entity{
public:
    Entity();
    Entity(vector2 pos, vector2 vel, TextureType type);
    void handleEvent();
    void update();
    void render();
private:
    vector2 pos;
    vector2 vel;
    SDL_Texture* tex;
protected:
    void setPos(vector2 p) {pos = p;}
    void setVel(vector2 v) {vel = v;}
};