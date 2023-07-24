#pragma once
#include "SDL2/SDL.h"
#include "headers/texture.h"
#include "headers/vector2.h"

class Entity{
public:
    Entity();
    Entity(vector2 pos, TextureType type);
    Entity(vector2 pos, TextureType type, vector2 size);
    virtual void handleEvent(SDL_Event e);
    virtual void update();
    virtual void render();
    vector2 getPos() {return pos;}
    vector2 getVel() {return vel;}
private:
    SDL_Texture* tex;
    const double gravity = 2000;
protected:
    double speed;
    vector2 pos;
    vector2 vel;
    vector2 size;

    bool isFlip;
};