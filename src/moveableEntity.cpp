#include "headers/movableEntity.h"
#include <stdio.h>

MovableEntity::MovableEntity() : Entity(){
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideType cType) : Entity(pos, tType, cType){
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideType cType, vector2 size) : Entity(pos, tType, cType, size){
}

void MovableEntity::handleEvent(SDL_Event e){
    Entity::handleEvent(e);
}

void MovableEntity::update(){
    Entity::update();
    CollideBox tmpBox = collideBox;
    vector2 dMove(0, 0);


    if(inAir){
        // tmpBox.setPos()
        Collision::isColliding(tmpBox, this, entities);
    }else{
        updateXPos(dMove, tmpBox);
    }

    pos = pos + dMove;
}

void MovableEntity::updateXPos(vector2& dMove, CollideBox tmpBox){
    tmpBox.setPos(new vector2(pos.x+vel.x * ((double)gb::getDelTicks() / 1000), pos.y));
    if(!Collision::isColliding(tmpBox, this, entities)){
        dMove.x = vel.x * ((double)gb::getDelTicks() / 1000);
    }
    else{
        if(vel.x > 0){
            pos.x = collidedEntityBox.getBoxLeft() - (size.x - collideBox.getBoxOffset().x);
        } 
        else if(vel.x < 0){
            pos.x = collidedEntityBox.getBoxRight() - collideBox.getBoxOffset().x + 1;
        }
    } 
}

void MovableEntity::render(){
    Entity::render();
}