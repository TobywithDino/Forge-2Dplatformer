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