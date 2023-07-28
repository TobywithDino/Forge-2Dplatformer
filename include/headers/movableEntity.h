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
    void updateXPos(vector2& dMove);
    // variables for JUMPING
    const double gravity = 5000;    
    double fallSpeedAfterCollision = 300;
protected:
    bool inAir = false;
    double speed = 100;
};