#pragma once
#include "movableEntity.h"

class Player : public MovableEntity{
public:
    Player();
    Player(vector2 pos);
    void handleEvent(SDL_Event e) override;
private:
    double jumpSpeed;
};