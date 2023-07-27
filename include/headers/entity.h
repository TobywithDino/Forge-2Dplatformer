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
    void setCollidedEntityBox(CollideBox c) {this->collidedEntityBox = c;}

    bool getActive() {return isActive;}
    CollideBox* getCollideBox() {return &collideBox;}
private:
    SDL_Texture* tex = Texture::getTexture(TEX_sprite_testBlock);
protected:
    bool isActive = true;
    vector2 pos = vector2(0,0);
    vector2 vel = vector2(0,0);
    vector2 size = vector2(32,32) * gb::getScale();
    bool isFlipping = false;
    CollideBox collideBox = CollideBox();
    Entity*** entities;
    CollideBox collidedEntityBox = CollideBox();
};