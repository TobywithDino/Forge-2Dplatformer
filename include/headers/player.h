#pragma once
#include "headers/weapon/weaponBox.h"

class Player : public MovableEntity{
public:
    Player();
    Player(vector2 pos);
    void handleEvent(SDL_Event e) override;
    void update() override;
    void render() override;
    void hurt(int damage) override{
        this->hp -= damage;
        Sound::playSFX(SFX_player_dead);
    }
private:
    void dropWeapon();
    void jump(vector2& tmpVel);
    double jumpSpeed = 1300;
    bool left = false;
    bool right = false;
    bool jumping = false;
    bool shooting = false;
    Weapon* weapon;
};