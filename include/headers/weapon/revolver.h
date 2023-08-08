#pragma once
#include "headers/weapon/weapon.h"

class Revolver : public Weapon{
public:
    Revolver() : Weapon(){}
    Revolver(vector2* playerPos) : 
    Weapon(playerPos, vector2(8,6), vector2(9,-3), 2000, 10, 900, TEX_weapon_revolver, TEX_projt_revolverBullet, COLBOX_projectile_revolverBullet){
        sfxType = SFX_weapon_revolver;
    }
};