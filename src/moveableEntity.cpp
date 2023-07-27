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
    
    vector2 dMove(0, 0);

    if(!inAir){
        CollideBox tmpBox = collideBox;
        tmpBox.setPos(new vector2(pos.x, pos.y+1));
        if(!Collision::isColliding(tmpBox, this, entities)){
            inAir = true;
        }
    }

    // when in air, check vertically
    if(inAir){
        CollideBox tmpBox = collideBox;
        tmpBox.setPos(new vector2(pos.x, pos.y+vel.y* ((double)gb::getFrameTicks() / 1000)));
        if(!Collision::isColliding(tmpBox, this, entities)){
            // if it is not hitting any roof or floor, move vertically
            dMove.y += vel.y * ((double)gb::getFrameTicks() / 1000);
            vel.y += gravity * ((double)gb::getFrameTicks() / 1000);
        }else{
            // if it's hitting roof or floor, move to the sides of the roof or floor
            pos.y = Collision::getYAfterCollision(vel.y, collideBox, collidedEntityBox);
            // after moved to correct y, check inAir state and update vel.y
            if(vel.y > 0){
                inAir = false;
                vel.y = 0;
            }
            else{
                vel.y = fallSpeedAfterCollision;
            }
        }
        // after checking vertically, check horizontally
        updateXPos(dMove);
    }else{
        // when not in air, only check horizontally
        updateXPos(dMove);
    }

    pos = pos + dMove;
}

void MovableEntity::updateXPos(vector2& dMove){
    // check horizontally
    CollideBox tmpBox = collideBox;
    tmpBox.setPos(new vector2(pos.x+vel.x * ((double)gb::getFrameTicks() / 1000), pos.y));
    if(!Collision::isColliding(tmpBox, this, entities)){
        // if it's not hitting walls, move horizontally
        dMove.x += vel.x * ((double)gb::getFrameTicks() / 1000);
    }
    else{
        // if it's hitting walls, move to the side of the walls
        pos.x = Collision::getXAfterCollision(vel.x, collideBox, collidedEntityBox);
    } 
}

void MovableEntity::render(){
    Entity::render();
}