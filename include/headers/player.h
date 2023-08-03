#pragma once
#include "headers/weapon/weaponBox.h"

class Player : public MovableEntity{
public:
    Player();
    Player(vector2 pos);
    void handleEvent(SDL_Event e) override;
    void update() override;
    void render() override;
private: 
    void jump(vector2& tmpVel);
    double jumpSpeed = 1200;
    bool left = false;
    bool right = false;
    bool jumping = false;
    bool shooting = false;
    Weapon* weapon;
};