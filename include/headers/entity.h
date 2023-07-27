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
    
    void setEntites(Entity*** e) {entities = e;}
    void setActive(bool isActive) {this->isActive = isActive;}

    bool getActive() {return isActive;}
    CollideBox* getCollideBox() {return collideBox;}
private:
    SDL_Texture* tex;
protected:
    bool isActive;
    vector2 pos;
    vector2 vel;
    vector2 size;
    bool isFlipping;
    CollideBox* collideBox;
    Entity*** entities;
};