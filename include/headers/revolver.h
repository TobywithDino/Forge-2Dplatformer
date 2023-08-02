#pragma once
#include "headers/weapon.h"

class Revolver : public Weapon{
public:
    Revolver() : Weapon(){}
    Revolver(vector2* playerPos) : 
    Weapon(playerPos, vector2(13,4), vector2(14,-3), 2000, 10, 1100, TEX_weapon_revolver, TEX_projt_revolverBullet, COLBOX_projectile_revolverBullet){}
};