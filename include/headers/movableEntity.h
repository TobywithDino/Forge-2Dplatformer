#pragma once
#include "headers/entity.h"
#include "headers/collider.h"
#include "headers/collideBox.h"
#include "headers/texture.h"

class MovableEntity : public Entity{
public:
    MovableEntity();
    MovableEntity(vector2 pos, TextureType tType, ColliderType cType);
    MovableEntity(vector2 pos, TextureType tType, ColliderType cType, vector2 size);
    virtual void handleEvent(SDL_Event e);
    virtual void update();
    vector2 getPos() {return pos;}
    vector2 getVel() {return vel;}
private:
    CollideBox* collideBox;
    const double gravity = 5000;
protected:
    double speed;
    vector2 vel;
};