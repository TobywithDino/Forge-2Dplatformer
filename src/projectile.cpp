#include "headers/weapon/projectile.h"
bool Projectile::discBulletOut = false;

Projectile::Projectile() : Entity(vector2(0,0), TEX_sprite_testBlock, COLBOX_default, COL_projectile){
    vel.x = 600;
}

Projectile::Projectile(vector2 pos, int speed, int damage, TextureType tType, CollideBoxType cbType) :  Entity(pos, tType, cbType, COL_projectile){
    vel.x = speed;
    this->damage = damage;
}

void Projectile::update(){
    if(Collision::isColliding(collideBox, this, COL_level)) isActive = false;
    if(!isActive) return;
    pos.x += vel.x * gb::getFrameTicks() / 1000;

    if(Collision::isColliding(collideBox, this, COL_enemy)) {
        isActive = false;
        collidedEntity->hurt(damage);
    }
    if(vel.x > 0) isFlipping = false;
    if(vel.x < 0) isFlipping = true;
}