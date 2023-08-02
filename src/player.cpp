#include "headers/player.h"

Player::Player() : MovableEntity(vector2(0,0), TEX_sprite_player, COLBOX_sprite_player, COL_player){
    speed = 320;
}

Player::Player(vector2 pos) : MovableEntity(pos, TEX_sprite_player, COLBOX_sprite_player, COL_player){
    speed = 320;
    WeaponBox tmpWeaponBox = WeaponBox();
    weapon = tmpWeaponBox.getWeapon(&this->pos);
}

void Player::handleEvent(SDL_Event e){
    MovableEntity::handleEvent(e);

    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_RIGHT) right = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_LEFT) left = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_Z) jumping = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_X) shooting = true;
    }
    if(e.type == SDL_KEYUP){
        if(e.key.keysym.scancode == SDL_SCANCODE_RIGHT) right = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_LEFT) left = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_Z) jumping = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_X) shooting = false;
    }
}

void Player::update(){
    if(Collision::isColliding(collideBox, this, COL_enemy) || pos.y > gb::getHeight()){
        gb::setGameState(GS_GameOver);
    }

    if(Collision::isColliding(collideBox, this, COL_weaponBox)){
        collidedEntity->setActive(false);
        WeaponBox* e = dynamic_cast<WeaponBox*>(collidedEntity);
        weapon = e->getWeapon(&this->pos); 
    }

    if(shooting && weapon != nullptr){
        weapon->shoot();
    }

    vector2 tmpVel(0, vel.y);
    if(right) tmpVel.x += speed;
    if(left) tmpVel.x -= speed;
    if(jumping) jump(tmpVel);

    vel = tmpVel;

    if(pos.y < 0){
        vel.x = 0;
    }

    MovableEntity::update();
}

void Player::render(){
    MovableEntity::render();
    if(weapon != nullptr){
        weapon->render(isFlipping);
    }
}

void Player::jump(vector2& tmpVel){
    if(inAir) return;
    inAir = true;
    tmpVel.y -= jumpSpeed;
}