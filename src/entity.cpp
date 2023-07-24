#include "headers/entity.h"
#include "headers/game.h"
#include <stdio.h>

Entity::Entity(){
    pos = vector2(0,0);
    tex = Texture::getTexture(TEX_sprite_testBlock);
    size = vector2(32, 32)*Game::getScale();
    isFlip = false;
}

Entity::Entity(vector2 pos, TextureType type){
    this->pos = pos;
    tex = Texture::getTexture(type);
    size = vector2(32, 32)*Game::getScale();
    isFlip = false;
}

Entity::Entity(vector2 pos, TextureType type, vector2 size){
    this->pos = pos;
    tex = Texture::getTexture(type);
    this->size = size*Game::getScale();
    isFlip = false;
}

void Entity::render(){
    SDL_Rect dst;
    dst.w = size.x;
    dst.h = size.y;
    dst.x = pos.x;
    dst.y = pos.y;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if(isFlip) flip = SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(Game::getRenderer(), tex, NULL, &dst, 0, NULL, flip);
}