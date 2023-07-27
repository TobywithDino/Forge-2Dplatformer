#pragma once
#include "movableEntity.h"

class Player : public MovableEntity{
public:
    Player();
    Player(vector2 pos);
    void handleEvent(SDL_Event e) override;
    void update() override;
private: 
    double jumpSpeed;
    bool left;
    bool right;
    bool jump;
};