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

    void setActive(bool isActive) {this->isActive = isActive;}
    void setPos(vector2 pos) {this->pos = pos;}
    void setVel(vector2 vel) {this->vel = vel;}
    void setIsOnGround(bool isOnGround) {this->isOnGround = isOnGround;}

    vector2 getPos() {return pos;}
    vector2 getVel() {return vel;}
    vector2 getSize() {return size;}
    bool getIsOnGround() {return isOnGround;}
    bool getActive() {return isActive;}
    CollideBox* getCollideBox() {return collideBox;}
private:
    SDL_Texture* tex;
protected:
    bool isActive;
    vector2 pos;
    vector2 vel;
    vector2 size;
    bool isFlip;
    bool isOnGround;
    CollideBox* collideBox;
};