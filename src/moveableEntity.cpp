#include "headers/movableEntity.h"
#include <stdio.h>

MovableEntity::MovableEntity() : Entity(){
    speed = 10;
    vel = vector2(0,0);
    collideBox = new CollideBox(COL_default, &this->pos);
}

MovableEntity::MovableEntity(vector2 pos, TextureType type, ColliderType cType) : Entity(pos, type){
    speed = 10;
    vel = vector2(0,0);
    collideBox = new CollideBox(cType, &this->pos);
}

MovableEntity::MovableEntity(vector2 pos, TextureType type, ColliderType cType, vector2 size) : Entity(pos, type, size){
    speed = 10;
    vel = vector2(0,0);
    collideBox = new CollideBox(cType, &this->pos);
}


void MovableEntity::handleEvent(SDL_Event e){
    collideBox->handleEvent(e);
}

void MovableEntity::update(){
    vel.y += gravity * gb::getDelTicks() / 1000;
    double dx = vel.x * gb::getDelTicks() / 1000;
    double dy = vel.y * gb::getDelTicks() / 1000;
    pos.x += dx;
    pos.y += dy;
    if(collideBox->checkHorizontal()) pos.x -= dx;
    if(collideBox->checkVertical()) pos.y -= dy;


    /* window height is the ground */

    // if(pos.y + size.y > gb::getHeight()){
    //     vel.y = 0;
    //     pos.y = gb::getHeight() - size.y;
    // }
}

void MovableEntity::render(){
    Entity::render();
    collideBox->render();
}