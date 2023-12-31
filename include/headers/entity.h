#pragma once
#include "headers/collideBox.h" 
#include "headers/anim.h"

class Entity{
// static part
public:
    static void setEntities(Entity*** e) {entities = e;}
    static Entity*** getEntities() {return entities;}
private:
    static Entity*** entities;

// non-static part
public:
    Entity();
    Entity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType);
    Entity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType, vector2 size);
    virtual void handleEvent(SDL_Event e);
    virtual void update();
    virtual void render();
    void setActive(bool isActive) {this->isActive = isActive;}
    void setCollidedEntity(Entity* e) {this->collidedEntity = e;}
    void setTexture(TextureType tType) {
        this->tType = tType;
        this->tex = Texture::getTexture(tType);
    }

    bool getActive() {return isActive;}
    CollideBox* getCollideBox() {return &collideBox;}
    TextureType getTextureType() {return tType;}

    virtual void hurt(int damage) {this->hp -= damage;}
private:
    SDL_Texture* tex = Texture::getTexture(TEX_sprite_testBlock);
protected:
    bool isActive = true;
    vector2 pos = vector2(0,0);
    vector2 vel = vector2(0,0);
    vector2 size = vector2(32,32);
    bool isFlipping = false;
    CollideBox collideBox = CollideBox();
    Entity* collidedEntity = this;
    int hp = 1;
    double angle = 0;
    TextureType tType = TEX_sprite_testBlock;
    Anim anim = Anim();
};