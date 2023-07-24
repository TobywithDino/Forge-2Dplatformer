#pragma once
#include "headers/entity.h"

class Player : public Entity{
public:
    Player();
    Player(vector2 pos);
    void handleEvent();
private:

};