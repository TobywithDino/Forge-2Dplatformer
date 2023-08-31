#include "headers/player.h"

Player::Player() : MovableEntity(vector2(0,0), TEX_sprite_player, COLBOX_sprite_player, COL_player){
    speed = 500;
}

Player::Player(vector2 pos) : MovableEntity(pos, TEX_sprite_player, COLBOX_sprite_player, COL_player){
    speed = 500;
    weapon = new Pistol(&this->pos);
    anim = Anim(&this->pos, TEX_sprite_player, ANIM_player_idle, ANIM_player_walk, ANIM_END);
}

void Player::handleEvent(SDL_Event e){
    if(hp <= 0) {
        shooting = false;
        return;
    }
    MovableEntity::handleEvent(e);

    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_RIGHT) right = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_LEFT) left = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_Z) jumping = true;
        if(e.key.keysym.scancode == SDL_SCANCODE_X) {
            if(!shooting && weapon != nullptr)
            {
                weapon->shoot();
                shooting = true;
            }
        }
    }
    if(e.type == SDL_KEYUP){
        if(e.key.keysym.scancode == SDL_SCANCODE_RIGHT) right = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_LEFT) left = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_Z) jumping = false;
        if(e.key.keysym.scancode == SDL_SCANCODE_X){
            shooting = false;
        }
    }
}

void Player::update(){
    if(Collision::isColliding(collideBox, this, COL_weaponBox)){
        // drop last weapon
        dropWeapon();

        // get weapon from box
        collidedEntity->setActive(false);
        WeaponBox* e = dynamic_cast<WeaponBox*>(collidedEntity);
        weapon = e->getWeapon(&this->pos);
        Sound::playSFX(SFX_player_pickWeapon);
        gb::setScore(gb::getScore()+1);
    }

    vector2 tmpVel(0, vel.y);
    if(right) tmpVel.x += speed;
    if(left) tmpVel.x -= speed;
    if(jumping) jump(tmpVel);

    vel = tmpVel;

    if(pos.y < 0){
        vel.x = 0;
    }

    if((pos.y > gb::getHeight() || Collision::isColliding(collideBox, this, COL_enemy)) && hp > 0){
        hp = 0;
        Sound::playSFX(SFX_player_dead);
        dropWeapon();
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

void Player::dropWeapon(){
    if(weapon == nullptr) return;
    MovableEntity *w = new MovableEntity(pos, weapon->getTextureType(), COLBOX_default, COL_END);
    w->hurt(2);
    AllSprite::addProjt(w);
    weapon = nullptr;
}