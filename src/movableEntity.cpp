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
    // drop dead when hp<=0 and don't run to pos update below.
    if(hp <= 0){
        collideBox.setCollideType(COL_END);
        dropDead();
        return;
    }

    vector2 dMove(0, 0);

    // when not in air(is on the ground), check if it's still on the ground this frame.
    if(!inAir){
        CollideBox tmpBox = collideBox;
        tmpBox.setPos(new vector2(pos.x, pos.y+2));
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
            // after moved to correct y, check vel.y and update inAir state
            if(vel.y > 0){
                inAir = false;
                vel.y = 0;
            }else if(vel.y < 0){
                vel.y = bounceSpeed;
            }
        }
        // after checking vertically, check horizontally
        updateXPos(dMove);
    }else{
        // when not in air, only check horizontally
        updateXPos(dMove);
    }

    // update pos
    pos = pos + dMove;

    // flip image according to vel.x
    if(vel.x > 0) isFlipping = false;
    if(vel.x < 0) isFlipping = true;
    
    // update anim state
    if(vel.x == 0) anim.setState(AS_idle);
    else anim.setState(AS_walk);

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

void MovableEntity::dropDead(){
    if(!jumpedAfterDead){
        jumpedAfterDead = true;
        vel.y = -500;
    }
    if(isFlipping) angle -= (hp-1);
    else angle += (hp-1);
    vector2 dMove;
    dMove.x += vel.x * gb::getFrameTicks() / 1000;
    dMove.y += vel.y * gb::getFrameTicks() / 1000;
    vel.y += gravity * gb::getFrameTicks() / 1000;
    pos = pos + dMove;
    if(pos.y > gb::getHeight()){
        isActive = false;
    }
}