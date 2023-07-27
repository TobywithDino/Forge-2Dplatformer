#pragma once
#include "headers/entity.h"

class Collision{
public:
    static bool isColliding(CollideBox aBox, Entity* a, Entity*** entities);
};