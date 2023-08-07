#pragma once
#include "headers/allSprite.h"

class Collision{
public:
    static bool isCollidingMouse(CollideBox aBox, vector2 mousePos);
    static bool isColliding(CollideBox aBox, Entity* a, CollideType colType);
    static double getDistance(CollideBox aBox, CollideType colType = COL_player);
    static double getXAfterCollision(double xV, CollideBox aBox, CollideBox bBox);
    static double getYAfterCollision(double yV, CollideBox aBox, CollideBox bBox);
};