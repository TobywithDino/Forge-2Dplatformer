#include "headers/collision.h"
#include <stdio.h>

bool Collision::isColliding(CollideBox aBox, Entity* a, Entity*** entities){
    for(int i=0;i<gb::maxEntities;i++){
        if(!(*entities[i])->getActive() || (*entities[i]) == a) continue;
        CollideBox* bBox = (*entities[i])->getCollideBox();
        if( aBox.getBoxLeft() < bBox->getBoxRight() && 
            aBox.getBoxRight() > bBox->getBoxLeft() &&
            aBox.getBoxTop() < bBox->getBoxDown() && 
            aBox.getBoxDown() > bBox->getBoxTop())
        {
            a->setCollidedEntityBox(*bBox);
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