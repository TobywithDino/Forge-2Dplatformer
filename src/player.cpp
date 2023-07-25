#include "headers/player.h"

Player::Player() : MovableEntity(vector2(0,0), TEX_sprite_player, COL_player){
    speed = 400;
    jumpSpeed = 1500;
}

Player::Player(vector2 pos) : MovableEntity(pos, TEX_sprite_player, COL_player){
    speed = 400;
    jumpSpeed = 1500;
}

void Player::handleEvent(SDL_Event e){
    MovableEntity::handleEvent(e);
    //keys can be hold or press multiple keys at the same time;
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
        if(vel.y >= 0) vel.y = -jumpSpeed;
    }

    // only detect press once and can't detect multiple keys
    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_Q){
            if(Map::getShowCollideBox()) Map::setShowCollideBox(false);
            else Map::setShowCollideBox(true);
        }
    }
}