#include "headers/movableEntity.h"

MovableEntity::MovableEntity() : Entity(){
    speed = 10;
    vel = vector2(0,0);
    collideBox = new CollideBox(COL_default, pos);
}

MovableEntity::MovableEntity(vector2 pos, TextureType type, ColliderType cType) : Entity(pos, type){
    speed = 10;
    vel = vector2(0,0);
    collideBox = new CollideBox(cType, pos);
}

MovableEntity::MovableEntity(vector2 pos, TextureType type, ColliderType cType, vector2 size) : Entity(pos, type, size){
    speed = 10;
    vel = vector2(0,0);
    collideBox = new CollideBox(cType, pos);
}


void MovableEntity::handleEvent(SDL_Event e){
    collideBox->handleEvent(e);
}

void MovableEntity::update(){
    vel.y += gravity * gb::getDelTicks() / 1000;
    pos.x += vel.x * gb::getDelTicks() / 1000;
    pos.y += vel.y * gb::getDelTicks() / 1000;
    if(pos.y + size.y > gb::getHeight()){
        vel.y = 0;
        pos.y = gb::getHeight() - size.y;
    }
}