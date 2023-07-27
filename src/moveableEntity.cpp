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
    CollideBox tmpBox = *collideBox;
    vector2 dMove(0, 0);

    tmpBox.setPos(new vector2(pos.x+vel.x * ((double)gb::getDelTicks() / 1000), pos.y));
    if(!Collision::isColliding(tmpBox, this, entities)) dMove.x = vel.x * ((double)gb::getDelTicks() / 1000);
    tmpBox.setPos(new vector2(pos.x, pos.y+vel.y * ((double)gb::getDelTicks() / 1000)));
    if(!Collision::isColliding(tmpBox, this, entities)) dMove.y = vel.y * ((double)gb::getDelTicks() / 1000);

    pos = pos + dMove;
    // if(isOnGround){
    //     if(vel.y > 0) vel.y = 0;
    // }else{
    //     vel.y += gravity * gb::getDelTicks() / 1000;
    // }


    // /* window height is the ground */
    // if(pos.y + size.y > gb::getHeight()){
    //     vel.y = 0;
    //     pos.y = gb::getHeight() - size.y;
    // }
}

void MovableEntity::render(){
    Entity::render();
}