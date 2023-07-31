#pragma once
#include "headers/collision.h"

class Projectile : public Entity{
public:
    Projectile();
    Projectile(vector2 pos, int speed, int damage, TextureType tType, CollideBoxType cbType);
    void update() override;
    int getDamage() {return damage;}
private:
    int damage = 1;
};