#pragma once
#include "headers/collision.h"

class Projectile : public Entity{
public:
    Projectile();
    Projectile(vector2 pos, double speed, TextureType tType, CollideBoxType cbType);
    void update() override;
};