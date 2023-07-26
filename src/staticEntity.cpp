#include "headers/staticEntity.h"
#include <stdio.h>

StaticEntity::StaticEntity() : Entity(){

}

StaticEntity::StaticEntity(vector<int>* box) : Entity(){
    collideBox = new CollideBox(box);
}

void StaticEntity::update(){
    return;
}

void StaticEntity::render(){
    collideBox->render();
}