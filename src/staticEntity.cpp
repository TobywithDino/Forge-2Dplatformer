#include "headers/staticEntity.h"

StaticEntity::StaticEntity() : Entity(){

}

StaticEntity::StaticEntity(vector<int>* box) : Entity(){
    // this constructor is for level which is not actually showing on screen
    show = false;
    collideBox = CollideBox(box);
}

void StaticEntity::render(){
    if(!show) return;
    Entity::render();
}