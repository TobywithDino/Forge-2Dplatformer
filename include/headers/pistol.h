#pragma once
#include "headers/weapon.h"

class Pistol : public Weapon{
public:
    Pistol() : Weapon(){}
    Pistol(vector2* playerPos) : Weapon(playerPos, vector2(10,6), vector2(4,0), 1400, 3, 450, TEX_weapon_pistol, TEX_projt_bullet, COLBOX_projectile_bullet){
    }
};