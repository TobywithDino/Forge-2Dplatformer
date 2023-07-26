#include "headers/entity.h"
#include <stdio.h>
Entity::Entity(){
    pos = vector2(0,0);
    tex = Texture::getTexture(TEX_sprite_none);
    size = vector2(32, 32)*gb::getScale();
    isFlip = false;
    collideBox = new CollideBox();
    dMove = vector2(0, 0);
}

Entity::Entity(vector2 pos, TextureType tType, CollideType cType){
    this->pos = pos;
    tex = Texture::getTexture(tType);
    size = vector2(32, 32)*gb::getScale();
    isFlip = false;
    collideBox = new CollideBox(cType, &this->pos);
    dMove = vector2(0, 0);
}

Entity::Entity(vector2 pos, TextureType tType, CollideType cType, vector2 size){
    this->pos = pos;
    tex = Texture::getTexture(tType);
    this->size = size*gb::getScale();
    isFlip = false;
    collideBox = new CollideBox(cType, &this->pos);
    dMove = vector2(0, 0);
}

void Entity::handleEvent(SDL_Event e){
    collideBox->handleEvent(e);
}

void Entity::update(){
    // if(collideBox->getIsCollidedHorizontal()){
    //     pos.x -= dMove.x;
    // }
    // if(collideBox->getIsCollidedVertical()){
    //     pos.y -= dMove.y;
    // }

    if(collideBox->getIsCollidedHorizontal() && collideBox->getIsCollidedVertical()){
        pos = pos - dMove;
    }
}

void Entity::render(){
    SDL_Rect dst;
    dst.w = size.x;
    dst.h = size.y;
    dst.x = pos.x;
    dst.y = pos.y;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if(isFlip) flip = SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(gb::getRenderer(), tex, NULL, &dst, 0, NULL, flip);
    collideBox->render();
}