#include "headers/player.h"

Player::Player() : MovableEntity(vector2(0,0), TEX_sprite_player){
    speed = 400;
    jumpSpeed = 1500;
}

Player::Player(vector2 pos) : MovableEntity(pos, TEX_sprite_player){
    speed = 400;
    jumpSpeed = 1500;
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

    if(keyboard[SDL_SCANCODE_SPACE]){
        vel.y = -jumpSpeed;
    }
}