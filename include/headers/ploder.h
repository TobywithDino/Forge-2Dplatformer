#pragma once
#include "headers/enemy.h"

class Ploder : public Enemy{
public:
    Ploder() : Enemy(){
    }
    Ploder(vector2 spawnPos) : Enemy(spawnPos, TEX_sprite_ploder, COLBOX_ploder){
        hp = 15;
        speed = 110;
        evolverType = TEX_sprite_ploder_evolved;
        newSpeed = 230;
        size = vector2(48, 48)*gb::getScale();
    }
};