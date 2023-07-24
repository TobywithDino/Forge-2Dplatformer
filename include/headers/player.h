#pragma once
#include "headers/entity.h"

class Player : public Entity{
public:
    Player() : Entity(vector2(0,0), vector2(0,0), TEX_player){}
    Player(vector2 pos) : Entity(pos, vector2(0,0), TEX_player){}
    void handleEvent();
private:

};