#include "headers/collideBox.h"

CollideBox::CollideBox(){
    box = Collider::getCollideBox(COL_default);
    showCollideBox = false;
    this->pos = nullptr;
}

CollideBox::CollideBox(ColliderType type, vector2& pos){
    box = Collider::getCollideBox(type);
    showCollideBox = false;
    this->pos = &pos;
}

void CollideBox::handleEvent(SDL_Event e){
    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_Q){
            if(showCollideBox) showCollideBox = false;
            else showCollideBox = true;
        }
    }
}

void CollideBox::update(){
    
}

void CollideBox::render(){
    if(!showCollideBox) return;
    int offsetX = box[0];
    int offsetY = box[1];
    int boxWidth = box[2];
    int boxHeight = box[3];
    SDL_Rect dst;
    dst.x =  pos->x + offsetX;
    dst.y =  pos->y + offsetY;
    dst.w = boxWidth;
    dst.h = boxHeight;
    SDL_SetRenderDrawColor(gb::getRenderer(), 0, 255, 0, 255);
    SDL_RenderFillRect(gb::getRenderer(), &dst);
}