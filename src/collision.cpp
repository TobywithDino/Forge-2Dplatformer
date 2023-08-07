#include "headers/collision.h"

bool Collision::isCollidingMouse(CollideBox aBox, vector2 mousePos){
    if( aBox.getBoxLeft() < mousePos.x && 
        aBox.getBoxRight() > mousePos.x &&
        aBox.getBoxTop() < mousePos.y && 
        aBox.getBoxDown() > mousePos.y)
    {
        return true;
    }
    return false;
}

bool Collision::isColliding(CollideBox aBox, Entity* a, CollideType colType){
    if(a->getCollideBox()->getCollideType() == COL_END) return false;
    Entity*** entities = Entity::getEntities();
    for(int i=0;i<gb::maxEntities;i++){
        if(!(*entities[i])->getActive() || (*entities[i]) == a || (*entities[i])->getCollideBox()->getCollideType() != colType) continue;
        CollideBox* bBox = (*entities[i])->getCollideBox();
        if( aBox.getBoxLeft() < bBox->getBoxRight() && 
            aBox.getBoxRight() > bBox->getBoxLeft() &&
            aBox.getBoxTop() < bBox->getBoxDown() && 
            aBox.getBoxDown() > bBox->getBoxTop())
        {
            a->setCollidedEntity(*entities[i]);
            return true;
        }
    }
    return false;
}

double Collision::getXAfterCollision(double xV, CollideBox aBox, CollideBox bBox){
    // get correct x pos after collision
    if(xV > 0){
        return bBox.getBoxLeft() - (aBox.getBoxSize().x + aBox.getBoxOffset().x) - 1;
    } 
    else if(xV < 0){
        return bBox.getBoxRight() - aBox.getBoxOffset().x + 1;
    }
    else{
        return aBox.getBoxLeft() - aBox.getBoxSize().x;
    }
}

double Collision::getYAfterCollision(double yV, CollideBox aBox, CollideBox bBox){
    // get correct y pos after collision
    if(yV > 0){
        return bBox.getBoxTop() - (aBox.getBoxSize().y + aBox.getBoxOffset().y) - 1;
    }
    else if(yV < 0){
        return bBox.getBoxDown() - aBox.getBoxOffset().y + 1;
    }
    else{
        return aBox.getBoxTop() - aBox.getBoxOffset().y;
    }
}

double Collision::getDistance(CollideBox aBox, CollideType colType){
    Entity*** entities = Entity::getEntities();
    double dis = 0;
    double minDis = 100000;
    for(int i=0;i<gb::maxEntities;i++){
        if((*entities[i])->getCollideBox()->getCollideType() != colType) continue;
        int dx = (*entities[i])->getCollideBox()->getBoxLeft() - aBox.getBoxLeft();
        int dy = (*entities[i])->getCollideBox()->getBoxTop() - aBox.getBoxTop();
        dis = sqrt(dx*dx + dy*dy);
        if(dis < minDis){
            minDis = dis;
        }
    }
    return minDis;
}