#pragma once
#include "headers/weapon.h"

class Dualgun : public Weapon{
public:
    Dualgun() : Weapon(){}
    Dualgun(vector2* playerPos) : 
    Weapon(playerPos, vector2(0,7), vector2(17,0), 700, 2, 280, TEX_weapon_dualgun, TEX_projt_dualgunBullet, COLBOX_projectile_dualgunBullet){}
    void shoot() override{
        if(SDL_GetTicks64() - lastShootTick >= shootDelayTicks){
            lastShootTick = SDL_GetTicks64();
            vector2 shootPos, shootPos2;
            int tmp_shootSpeed;
            shootPos.y = pos.y + shootOffsetPos.y;
            shootPos2.y = shootPos.y;
            int pjtSizeX = 32*gb::getScale();
            double pivotX = pos.x + size.x - pjtSizeX;
            if(isFlipping) {
                shootPos.x = pivotX - shootOffsetPos.x;
                shootPos2.x = pos.x + shootOffsetPos.x;
                tmp_shootSpeed = -1*shootSpeed;
            }
            else {
                shootPos.x = pos.x + shootOffsetPos.x;
                shootPos2.x = pivotX - shootOffsetPos.x;
                tmp_shootSpeed = shootSpeed;
            }
            Projectile* projt = new Projectile(shootPos, tmp_shootSpeed, damage, projtTType, projtCBType);
            Projectile* projt2 = new Projectile(shootPos2, tmp_shootSpeed*-1, damage, projtTType, projtCBType);
            AllSprite::addProjt(projt);
            AllSprite::addProjt(projt2);
        }
    }
};