#include "headers/button.h"
bool Button::holdingAButton = false;

Button::Button(){
}

Button::Button(vector2 pos, TextureType tType_unPress, TextureType tType_pressed, CollideBoxType cbType, vector2 size, GameState dstState){
    size = size * gb::getScale();
    vector2 center = vector2(pos.x - size.x/2, pos.y - size.y/2);
    this->pos = center;
    this->unPressTex = tType_unPress;
    this->pressedTex = tType_pressed;
    setTexture(unPressTex);
    this->collideBox = CollideBox(cbType, &this->pos, COL_button);
    this->size = size;
    this->dstState = dstState;
}

void Button::handleEvent(SDL_Event e){
    Sint32 mouseX = e.motion.x;
    Sint32 mouseY = e.motion.y;
    vector2 mousePos = vector2(mouseX, mouseY);

    if(e.type == SDL_MOUSEBUTTONDOWN){
        if(Collision::isCollidingMouse(this->collideBox, mousePos) && !holdingAButton){
            pressing = true;
            holdingAButton = true;
            setTexture(pressedTex);
        }
    }
    if(e.type == SDL_MOUSEBUTTONUP){
        pressing = false;
        holdingAButton = false;
        setTexture(unPressTex);
        if(Collision::isCollidingMouse(this->collideBox, mousePos)){
            gb::setGameState(dstState);
        }
    }
}

void Button::update(){
}