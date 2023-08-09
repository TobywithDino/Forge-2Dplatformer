#include "headers/weapon/weapon.h"

Weapon::Weapon() : Entity(){
}

Weapon::Weapon(vector2* playerPos, vector2 offset, vector2 shootOffsetPos, int shootSpeed, int damage, int shootDelayTicks, TextureType weaponTType, TextureType projtTType, CollideBoxType projtCBType){
    this->playerPos = playerPos;
    this->offset = offset * gb::getScale();
    this->shootOffsetPos = shootOffsetPos * gb::getScale();
    this->shootSpeed = shootSpeed;
    this->damage = damage;
    this->projtTType = projtTType;
    this->projtCBType = projtCBType;
    this->shootDelayTicks = shootDelayTicks;
    setTexture(weaponTType);
}

void Weapon::render(bool flip){
    isFlipping = flip;
    pos.y = playerPos->y + offset.y;
    if(isFlipping){
        int playerSizeX = 32*gb::getScale();
        double pivotX = playerPos->x+playerSizeX-size.x*gb::getScale();
        pos.x = pivotX - offset.x;
    }else{
        pos.x = playerPos->x + offset.x;
    }
    Entity::render();
}

void Weapon::shoot(){
    if(SDL_GetTicks64() - lastShootTick >= shootDelayTicks){
        lastShootTick = SDL_GetTicks64();
        vector2 shootPos;
        int tmp_shootSpeed;
        shootPos.y = pos.y + shootOffsetPos.y;
        if(isFlipping) {
            int pjtSizeX = 32*gb::getScale();
            double pivotX = pos.x + size.x*gb::getScale() - pjtSizeX;
            shootPos.x = pivotX - shootOffsetPos.x;
            tmp_shootSpeed = -1*shootSpeed;
        }
        else {
            shootPos.x = pos.x + shootOffsetPos.x;
            tmp_shootSpeed = shootSpeed;
        }
        Projectile* projt = new Projectile(shootPos, tmp_shootSpeed, damage, projtTType, projtCBType);
        AllSprite::addProjt(projt);
        Sound::playSFX(sfxType);
    }
}