#pragma once
#include "SDL2/SDL.h"
#include "headers/gb.h"
#include "headers/vector2.h"
#include "headers/texture.h"
class Entity{
public:
    Entity();
    Entity(vector2 pos, TextureType type);
    Entity(vector2 pos, TextureType type, vector2 size);
    virtual void render();
private:
    SDL_Texture* tex;
protected:
    vector2 pos;
    vector2 size;
    bool isFlip;
};