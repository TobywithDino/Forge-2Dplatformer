#include "headers/player.h"
#include <stdio.h>

Player::Player() : MovableEntity(vector2(0,0), TEX_sprite_player, COL_player){
    speed = 400;
}

Player::Player(vector2 pos) : MovableEntity(pos, TEX_sprite_player, COL_player){
    speed = 400;
}

void Player::handleEvent(SDL_Event e){
    MovableEntity::handleEvent(e);

    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_D) right = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_A) left = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_SPACE) jump = true;
    }
    if(e.type == SDL_KEYUP){
        if(e.key.keysym.scancode == SDL_SCANCODE_D) right = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_A) left = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_SPACE) jump = false;
    }
}

void Player::update(){
    vector2 tmpVel(0, 0);
    if(right) tmpVel.x += speed;
    if(left) tmpVel.x -= speed;

    if(tmpVel.x < 0) isFlipping = true;
    else isFlipping = false;

    
   
    vel = tmpVel;
    MovableEntity::update();
}