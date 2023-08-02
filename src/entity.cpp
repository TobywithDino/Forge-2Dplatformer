#include "headers/entity.h"

Entity*** Entity::entities;

Entity::Entity(){
}

Entity::Entity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType){
    this->pos = pos;
    tex = Texture::getTexture(tType);
    collideBox = CollideBox(cbType, &this->pos, cType);
}

Entity::Entity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType, vector2 size){
    this->pos = pos;
    vel = vector2(0,0);
    tex = Texture::getTexture(tType);
    this->size = size*gb::getScale();
    collideBox = CollideBox(cbType, &this->pos, cType);
}

void Entity::handleEvent(SDL_Event e){
}

void Entity::update(){
    if(hp <= 0) isActive = false;
    if(vel.x > 0) isFlipping = false;
    if(vel.x < 0) isFlipping = true;
}

void Entity::render(){
    SDL_Rect dst;
    dst.w = size.x;
    dst.h = size.y;
    dst.x = (int)pos.x;
    dst.y = (int)pos.y;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if(isFlipping) flip = SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(gb::getRenderer(), tex, NULL, &dst, 0, NULL, flip);
}