#include "headers/player.h"

Player::Player() : MovableEntity(vector2(0,0), TEX_sprite_player, COLBOX_player, COL_player){
    speed = 400;
}

Player::Player(vector2 pos) : MovableEntity(pos, TEX_sprite_player, COLBOX_player, COL_player){
    speed = 400;
}

void Player::handleEvent(SDL_Event e){
    MovableEntity::handleEvent(e);

    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_RIGHT) right = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_LEFT) left = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_Z) jumping = true;
    }
    if(e.type == SDL_KEYUP){
        if(e.key.keysym.scancode == SDL_SCANCODE_RIGHT) right = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_LEFT) left = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_Z) jumping = false;
    }
}

void Player::update(){
    vector2 tmpVel(0, vel.y);
    if(right) tmpVel.x += speed;
    if(left) tmpVel.x -= speed;
    if(jumping) jump(tmpVel);

    vel = tmpVel;
    if(Collision::isColliding(collideBox, this, COL_enemy)){
        gb::setGameState(GS_GameOver);
    }
    if(pos.y > gb::getHeight()){
        gb::setGameState(GS_GameOver);
    }
    if(pos.y < 0){
        vel.x = 0;
    }

    MovableEntity::update();
}

void Player::jump(vector2& tmpVel){
    if(inAir) return;
    inAir = true;
    tmpVel.y -= jumpSpeed;
}