#include "headers/movableEntity.h"
#include <stdio.h>

MovableEntity::MovableEntity() : Entity(){
    speed = 10;
    vel = vector2(0,0);
    dMove = vector2(0,0);
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideType cType) : Entity(pos, tType, cType){
    speed = 10;
    vel = vector2(0,0);
    dMove = vector2(0,0);
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideType cType, vector2 size) : Entity(pos, tType, cType, size){
    speed = 10;
    vel = vector2(0,0);
    dMove = vector2(0,0);
}


void MovableEntity::handleEvent(SDL_Event e){
    Entity::handleEvent(e);
}

void MovableEntity::update(){
    vel.y += gravity * gb::getDelTicks() / 1000;
    dMove.x = vel.x * gb::getDelTicks() / 1000;
    dMove.y = vel.y * gb::getDelTicks() / 1000;
    pos = pos + dMove;

    /* window height is the ground */
    if(pos.y + size.y > gb::getHeight()){
        vel.y = 0;
        pos.y = gb::getHeight() - size.y;
    }
}

void MovableEntity::render(){
    Entity::render();
}