#pragma once
#include "headers/weapon/weapon.h"
#include "headers/weapon/discBullet.h"

class Disc : public Weapon{
public:
    Disc() : Weapon(){
        Projectile::setDiscBulletOut(false);
    }
    Disc(vector2* playerPos) : 
    Weapon(playerPos, vector2(10,6), vector2(4,0), 1100, 10, TEX_weapon_disc, TEX_projt_discBullet, COLBOX_projectile_discBullet){
        Projectile::setDiscBulletOut(false);
        sfxType = SFX_weapon_disc;
    }
    void shoot() override{
        if(Projectile::getDiscBulletOut()) return;
        Projectile::setDiscBulletOut(true);
        vector2 shootPos;
        int tmp_shootSpeed;
        shootPos.y = pos.y + shootOffsetPos.y;
        if(isFlipping) {
            int pjtSizeX = 32*gb::getScale();
            double pivotX = pos.x + size.x - pjtSizeX;
            shootPos.x = pivotX - shootOffsetPos.x;
            tmp_shootSpeed = -1*shootSpeed;
        }
        else {
            shootPos.x = pos.x + shootOffsetPos.x;
            tmp_shootSpeed = shootSpeed;
        }
        Projectile* projt = new DiscBullet(shootPos, tmp_shootSpeed, damage);
        AllSprite::addProjt(projt);
        Sound::playSFX(sfxType);
    }
};