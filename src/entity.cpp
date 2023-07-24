#include "headers/entity.h"
#include "headers/game.h"

Entity::Entity(){
    pos = vector2(0,0);
    vel = vector2(0,0);
    tex = Texture::getTexture(TEX_player);
}

Entity::Entity(vector2 pos, vector2 vel, TextureType type){
    this->pos = pos;
    this->vel = vel;
    tex = Texture::getTexture(type);
}

void Entity::update(){
    pos.x += vel.x * Game::getDelTicks() / 1000;
    pos.y += vel.y * Game::getDelTicks() / 1000;
}

void Entity::render(){
    SDL_Rect dst;
    dst.w = dst.h = (int)((double)32 * Game::getScale());
    dst.x = pos.x;
    dst.y = pos.y;
    SDL_RenderCopy(Game::getRenderer(), tex, NULL, &dst);
}