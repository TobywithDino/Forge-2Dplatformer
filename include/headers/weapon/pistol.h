#pragma once
#include "headers/weapon/weapon.h"

class Pistol : public Weapon{
public:
    Pistol() : Weapon(){}
    Pistol(vector2* playerPos) : 
    Weapon(playerPos, vector2(10,6), vector2(4,-1), 1300, 1, TEX_weapon_pistol, TEX_projt_pistolBullet, COLBOX_projectile_pistolBullet){
        sfxType = SFX_weapon_pistol;
    }
};