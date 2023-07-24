#include "headers/entity.h"
#include "headers/game.h"

Entity::Entity(){
    pos = vector2(0,0);
    vel = vector2(0,0);
    tex = Texture::getTexture(TEX_testBlock);
    size = vector2(32, 32);
}

Entity::Entity(vector2 pos, vector2 vel, TextureType type){
    this->pos = pos;
    this->vel = vel;
    tex = Texture::getTexture(type);
    size = vector2(32, 32);
}

Entity::Entity(vector2 pos, vector2 vel, TextureType type, vector2 size){
    this->pos = pos;
    this->vel = vel;
    tex = Texture::getTexture(type);
    this->size = size;
}


void Entity::handleEvent(){
    
}

void Entity::update(){
    // vel.y += gravity * Game::getDelTicks() / 1000;

    pos.x += vel.x * Game::getDelTicks() / 1000;
    pos.y += vel.y * Game::getDelTicks() / 1000;
    if(pos.y + size.y > Game::getHeight()){
        vel.y = 0;
        pos.y = Game::getHeight() - size.y;
    }
}

void Entity::render(){
    SDL_Rect dst;
    dst.w = (int)(size.x * Game::getScale());
    dst.h = (int)(size.y * Game::getScale());
    dst.x = pos.x;
    dst.y = pos.y;
    SDL_RenderCopy(Game::getRenderer(), tex, NULL, &dst);
}