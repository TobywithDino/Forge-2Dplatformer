#include "headers/collideBox.h"
#include <stdio.h>
CollideBox::CollideBox(){
    box = Collider::getCollideBox(COL_default);
    showCollideBox = false;
    this->pos = nullptr;
}

CollideBox::CollideBox(ColliderType type, vector2* pos){
    box = Collider::getCollideBox(type);
    showCollideBox = false;
    this->pos = pos;
}

void CollideBox::handleEvent(SDL_Event e){
    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_Q){
            if(showCollideBox) showCollideBox = false;
            else showCollideBox = true;
        }
    }
}

bool CollideBox::checkHorizontal(){

    return false;
}

bool CollideBox::checkVertical(){

    return false;
}

void CollideBox::render(){
    if(!showCollideBox) return;
    int offsetX = box->at(0);
    int offsetY = box->at(1);
    int boxWidth = box->at(2);
    int boxHeight = box->at(3);
    SDL_Rect dst;
    dst.x =  pos->x + offsetX * gb::getScale();
    dst.y =  pos->y + offsetY * gb::getScale();
    dst.w = boxWidth * gb::getScale();
    dst.h = boxHeight * gb::getScale();
    SDL_SetRenderDrawColor(gb::getRenderer(), 0, 255, 0, 255);
    SDL_RenderDrawRect(gb::getRenderer(), &dst);
}