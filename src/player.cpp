#include "headers/player.h"

Player::Player() : Entity(vector2(0,0), TEX_player){
    speed = 400;
}

Player::Player(vector2 pos) : Entity(pos, TEX_player){
    speed = 400;
}

void Player::handleEvent(SDL_Event e){
    const Uint8* keyboard = SDL_GetKeyboardState(NULL);
    if(keyboard[SDL_SCANCODE_D]){
        vel.x = speed;
        isFlip = false;
    }else if(keyboard[SDL_SCANCODE_A]){
        vel.x = -speed;
        isFlip = true;
    }else{
        vel.x = 0;
    }
}