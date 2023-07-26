#include "headers/movableEntity.h"
#include <stdio.h>

MovableEntity::MovableEntity() : Entity(){
    speed = 10;
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideType cType) : Entity(pos, tType, cType){
    speed = 10;
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideType cType, vector2 size) : Entity(pos, tType, cType, size){
    speed = 10;
}


void MovableEntity::handleEvent(SDL_Event e){
    Entity::handleEvent(e);
}

void MovableEntity::update(){
    Entity::update();
    vel.y += gravity * gb::getDelTicks() / 1000;
    pos = pos + vel * ((double)gb::getDelTicks() / 1000);

    /* window height is the ground */
    if(pos.y + size.y > gb::getHeight()){
        vel.y = 0;
        pos.y = gb::getHeight() - size.y;
    }
}

void MovableEntity::render(){
    Entity::render();
}