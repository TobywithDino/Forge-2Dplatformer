#pragma once
#include "headers/entity.h"
#include "headers/collideBox.h"
#include "headers/texture.h"

class MovableEntity : public Entity{
public:
    MovableEntity();
    MovableEntity(vector2 pos, TextureType tType, CollideType cType);
    MovableEntity(vector2 pos, TextureType tType, CollideType cType, vector2 size);
    virtual void handleEvent(SDL_Event e);
    virtual void update();
    virtual void render() override;
    vector2 getPos() {return pos;}
    vector2 getVel() {return vel;}
private:
    const double gravity = 5000;
protected:
    CollideBox* collideBox;
    double speed;
    vector2 vel;
};