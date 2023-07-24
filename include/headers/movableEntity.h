#pragma once
#include "headers/entity.h"

class MovableEntity : public Entity{
public:
    MovableEntity();
    MovableEntity(vector2 pos, TextureType type);
    MovableEntity(vector2 pos, TextureType type, vector2 size);
    virtual void handleEvent(SDL_Event e);
    virtual void update();
    vector2 getPos() {return pos;}
    vector2 getVel() {return vel;}
private:
    SDL_Texture* tex;
    const double gravity = 3000;
protected:
    double speed;
    vector2 vel;
};