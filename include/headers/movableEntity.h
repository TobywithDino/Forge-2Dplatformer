#pragma once
#include "headers/entity.h"
#include "headers/collision.h"

class MovableEntity : public Entity{
public:
    MovableEntity();
    MovableEntity(vector2 pos, TextureType tType, CollideType cType);
    MovableEntity(vector2 pos, TextureType tType, CollideType cType, vector2 size);
    virtual void handleEvent(SDL_Event e) override;
    virtual void update() override;
    virtual void render() override;
private:
    void updateXPos(vector2& dMove, CollideBox tmpBox);
    // variables for JUMPING
    const double gravity = 5000;
    double airSpeed = 0;
    double jumpSpeed = 1500;
    double fallSpeedAfterCollision = 700;
    bool inAir = false;
protected:
    double speed = 100;
};