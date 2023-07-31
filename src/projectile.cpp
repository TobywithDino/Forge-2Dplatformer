#include "headers/weapon/projectile.h"

Projectile::Projectile() : Entity(vector2(0,0), TEX_sprite_testBlock, COLBOX_default, COL_projectile){
    vel.x = 600;
}

Projectile::Projectile(vector2 pos, double speed, TextureType tType, CollideBoxType cbType) :  Entity(pos, tType, cbType, COL_projectile){
    vel.x = speed;
}

void Projectile::update(){
    pos.x += vel.x * gb::getFrameTicks() / 1000;
    Entity::update();
}