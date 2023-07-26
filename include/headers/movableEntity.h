#pragma once
#include "headers/entity.h"

class MovableEntity : public Entity{
public:
    MovableEntity();
    MovableEntity(vector2 pos, TextureType tType, CollideType cType);
    MovableEntity(vector2 pos, TextureType tType, CollideType cType, vector2 size);
    virtual void handleEvent(SDL_Event e) override;
    virtual void update() override;
    virtual void render() override;
private:
    const double gravity = 5000;
protected:
    double speed;
};