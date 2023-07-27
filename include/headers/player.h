#pragma once
#include "movableEntity.h"

class Player : public MovableEntity{
public:
    Player();
    Player(vector2 pos);
    void handleEvent(SDL_Event e) override;
    void update() override;
private: 
    void jump(vector2& tmpVel);
    double jumpSpeed = 1500;
    bool left = false;
    bool right = false;
    bool jumping = false;
};