#pragma once
#include "headers/entity.h"

class Collision{
public:
    static bool isColliding(CollideBox aBox, Entity* a, Entity*** entities);
    static double getXAfterCollision(double xV, CollideBox aBox, CollideBox bBox);
    static double getYAfterCollision(double yV, CollideBox aBox, CollideBox bBox);
};