#pragma once
#include "headers/movableEntity.h"

class Enemy : public MovableEntity{
public:
    Enemy();
    Enemy(vector2 pos, TextureType tType, CollideBoxType cbType);
};