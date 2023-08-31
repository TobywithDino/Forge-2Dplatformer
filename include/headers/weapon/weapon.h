#pragma once
#include "headers/weapon/projectile.h"

class Weapon : public Entity{
public:
    Weapon();
    Weapon(vector2* playerPos,vector2 offset, vector2 shootOffsetPos, int shootSpeed, int damage, TextureType weaponTType, TextureType projtTType, CollideBoxType projtCBType);
    void render(bool flip);
    virtual void shoot();
protected:
    vector2* playerPos = new vector2(0,0);
    vector2 offset = vector2(0,0);
    vector2 shootOffsetPos = vector2(0,0);
    int shootSpeed = 600;
    int damage = 1;
    TextureType projtTType;
    CollideBoxType projtCBType;
    SFXType sfxType = SFX_END;
};