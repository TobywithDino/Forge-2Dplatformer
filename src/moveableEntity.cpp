#include "headers/game.h"
#include "headers/movableEntity.h"

MovableEntity::MovableEntity() : Entity(){
    speed = 10;
    vel = vector2(0,0);
}

MovableEntity::MovableEntity(vector2 pos, TextureType type) : Entity(pos, type){
    speed = 10;
    vel = vector2(0,0);
}

MovableEntity::MovableEntity(vector2 pos, TextureType type, vector2 size) : Entity(pos, type, size){
    speed = 10;
    vel = vector2(0,0);
}


void MovableEntity::handleEvent(SDL_Event e){
    
}

void MovableEntity::update(){
    vel.y += gravity * Game::getDelTicks() / 1000;
    pos.x += vel.x * Game::getDelTicks() / 1000;
    pos.y += vel.y * Game::getDelTicks() / 1000;
    if(pos.y + size.y > Game::getHeight()){
        vel.y = 0;
        pos.y = Game::getHeight() - size.y;
    }
}