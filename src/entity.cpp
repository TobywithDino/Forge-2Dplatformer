#include "headers/entity.h"

Entity*** Entity::entities;

Entity::Entity(){
}

Entity::Entity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType){
    this->pos = pos;
    this->tType = tType;
    tex = Texture::getTexture(tType);
    collideBox = CollideBox(cbType, &this->pos, cType);
}

Entity::Entity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType, vector2 size){
    this->pos = pos;
    vel = vector2(0,0);
    this->tType = tType;
    tex = Texture::getTexture(tType);
    this->size = size*gb::getScale();
    collideBox = CollideBox(cbType, &this->pos, cType);
}

void Entity::handleEvent(SDL_Event e){
}

void Entity::update(){
}

void Entity::render(){
    SDL_Rect dst;
    dst.w = size.x;
    dst.h = size.y;
    dst.x = (int)pos.x;
    dst.y = (int)pos.y;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if(isFlipping) flip = SDL_FLIP_HORIZONTAL;
    
    if(!anim.getOnAnim()) SDL_RenderCopyEx(gb::getRenderer(), tex, NULL, &dst, angle, NULL, flip);
    else anim.render(angle, flip);
}