#include "headers/movableEntity.h"

MovableEntity::MovableEntity() : Entity(){
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType) : Entity(pos, tType, cbType, cType){
}

MovableEntity::MovableEntity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType, vector2 size) : Entity(pos, tType, cbType, cType, size){
}

void MovableEntity::handleEvent(SDL_Event e){
    Entity::handleEvent(e);
}

void MovableEntity::update(){
    
    vector2 dMove(0, 0);

    if(!inAir){
        CollideBox tmpBox = collideBox;
        tmpBox.setPos(new vector2(pos.x, pos.y+1));
        if(!Collision::isColliding(tmpBox, this, COL_level)){
            inAir = true;
        }
    }

    // when in air, check vertically
    if(inAir){
        CollideBox tmpBox = collideBox;
        tmpBox.setPos(new vector2(pos.x, pos.y+vel.y* ((double)gb::getFrameTicks() / 1000)));
        if(!Collision::isColliding(tmpBox, this, COL_level)){
            // if it is not hitting any roof or floor, move vertically
            dMove.y += vel.y * ((double)gb::getFrameTicks() / 1000);
            vel.y += gravity * ((double)gb::getFrameTicks() / 1000);
        }else{
            // if it's hitting roof or floor, move to the sides of the roof or floor
            pos.y = Collision::getYAfterCollision(vel.y, collideBox, *(collidedEntity->getCollideBox()));
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
    Entity::update();
}

void MovableEntity::updateXPos(vector2& dMove){
    // check horizontally
    CollideBox tmpBox = collideBox;
    tmpBox.setPos(new vector2(pos.x+vel.x * ((double)gb::getFrameTicks() / 1000), pos.y));
    if(!Collision::isColliding(tmpBox, this, COL_level)){
        // if it's not hitting walls, move horizontally
        dMove.x += vel.x * ((double)gb::getFrameTicks() / 1000);
    }
    else{
        // if it's hitting walls, move to the side of the walls
        pos.x = Collision::getXAfterCollision(vel.x, collideBox, *(collidedEntity->getCollideBox()));
    } 
}

void MovableEntity::render(){
    Entity::render();
}