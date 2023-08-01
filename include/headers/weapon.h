#pragma once
#include "headers/projectile.h"

class Weapon : public Entity{
public:
    Weapon();
    Weapon(vector2* playerPos,vector2 offset, vector2 shootOffsetPos, int shootSpeed, int damage, int shootDelayTicks, TextureType weaponTType, TextureType projtTType, CollideBoxType projtCBType);
    void render(bool flip);
    void shoot();
private:
    vector2* playerPos = new vector2(0,0);
    vector2 offset = vector2(0,0);
    vector2 shootOffsetPos = vector2(0,0);
    int shootSpeed = 600;
    int damage = 1;
    TextureType projtTType;
    CollideBoxType projtCBType;
    int shootDelayTicks = 500;
    Uint64 lastShootTick = 0;
};