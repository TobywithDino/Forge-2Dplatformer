#pragma once
#include "headers/weapon.h"

class Revolver : public Weapon{
public:
    Revolver() : Weapon(){}
    Revolver(vector2* playerPos) : 
    Weapon(playerPos, vector2(16,4), vector2(14,-3), 1600, 10, 1200, TEX_weapon_revolver, TEX_projt_revolverBullet, COLBOX_projectile_revolverBullet){}
};