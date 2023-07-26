#pragma once
#include "SDL2/SDL.h"
#include "headers/collideBox.h" 
#include "headers/texture.h"

class Entity{
public:
    Entity();
    Entity(vector2 pos, TextureType tType, CollideType cType);
    Entity(vector2 pos, TextureType tType, CollideType cType, vector2 size);
    virtual void handleEvent(SDL_Event e);
    virtual void update();
    virtual void render();
    CollideBox* getCollideBox() {return collideBox;}
    void setActive(bool active) {isActive = active;}
private:
    SDL_Texture* tex;
protected:
    bool isActive;
    vector2 dMove;
    vector2 pos;
    vector2 size;
    bool isFlip;
    CollideBox* collideBox;
};