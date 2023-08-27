#pragma once
#include "headers/collision.h"

class MovableEntity : public Entity{
public:
    MovableEntity();
    MovableEntity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType);
    MovableEntity(vector2 pos, TextureType tType, CollideBoxType cbType, CollideType cType, vector2 size);
    virtual void handleEvent(SDL_Event e) override;
    virtual void update() override;
    virtual void render() override;
private:
    bool jumpedAfterDead = false;
    void dropDead();
    void updateXPos(vector2& dMove);
    const double gravity = 4000;
    const double bounceSpeed = 400;  
protected:
    bool inAir = false;
    double speed = 100;
};