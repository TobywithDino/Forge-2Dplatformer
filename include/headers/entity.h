#pragma once
#include "SDL2/SDL.h"
#include "headers/gb.h"
#include "headers/vector2.h"
#include "headers/texture.h"
#include "headers/collideBox.h"

class Entity{
public:
    Entity();
    Entity(vector2 pos, TextureType tType, CollideType cType);
    Entity(vector2 pos, TextureType tType, CollideType cType, vector2 size);
    virtual void render();
    virtual void handleEvent(SDL_Event e);
private:
    SDL_Texture* tex;
protected:
    vector2 pos;
    vector2 size;
    bool isFlip;
    CollideBox* collideBox;
};