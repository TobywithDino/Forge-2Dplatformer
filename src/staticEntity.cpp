#include "headers/staticEntity.h"
#include <stdio.h>

StaticEntity::StaticEntity() : Entity(){

}

StaticEntity::StaticEntity(vector<int>* box) : Entity(){
    collideBox = CollideBox(box);
}

void StaticEntity::render(){
    if(!isActive) return;
    collideBox.render();
}