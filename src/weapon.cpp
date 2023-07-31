#include "headers/weapon.h"

Weapon::Weapon(){
}

Weapon::Weapon(vector2* playerPos, vector2 shootOffsetPos, int shootSpeed, int damage, int shootDelayTicks, TextureType weaponTType, TextureType projtTType, CollideBoxType projtCBType){
    this->playerPos = playerPos;
    this->shootOffsetPos = shootOffsetPos * gb::getScale();
    this->shootSpeed = shootSpeed;
    this->damage = damage;
    this->projtTType = projtTType;
    this->projtCBType = projtCBType;
    this->shootDelayTicks = shootDelayTicks;
    setTexture(weaponTType);
}

void Weapon::render(){
    pos = *playerPos;
    Entity::render();
}

void Weapon::shoot(){
    if(SDL_GetTicks64() - lastShootTick >= shootDelayTicks){
        lastShootTick = SDL_GetTicks64();
        vector2 shootPos;
        int tmp_shootSpeed;
        shootPos.y = pos.y + shootOffsetPos.y;
        if(isFlipping) {
            shootPos.x = pos.x - shootOffsetPos.x;
            tmp_shootSpeed = -1*shootSpeed;
        }
        else {
            shootPos.x = pos.x + shootOffsetPos.x;
            tmp_shootSpeed = shootSpeed;
        }
        Projectile* projt = new Projectile(shootPos, tmp_shootSpeed, damage, projtTType, projtCBType);
        AllSprite::addProjt(projt);
    }
}