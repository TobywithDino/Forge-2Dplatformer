#pragma once
#include "headers/collision.h"

class Projectile : public Entity{
public:
    Projectile();
    Projectile(vector2 pos, int speed, int damage, TextureType tType, CollideBoxType cbType);
    void update() override;
    int getDamage() {return damage;}
    static bool getDiscBulletOut() {return discBulletOut;}
    static void setDiscBulletOut(bool out) {discBulletOut = out;}
private:
    static bool discBulletOut;
protected:
    int damage = 1;
};