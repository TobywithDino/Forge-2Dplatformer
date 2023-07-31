#pragma once
#include "headers/enemy.h"

class Ploder : public Enemy{
public:
    Ploder() : Enemy(){
    }
    Ploder(vector2 spawnPos) : Enemy(spawnPos, TEX_sprite_ploder, COLBOX_sprite_ploder){
        hp = 20;
        speed = 120;
        evolverType = TEX_sprite_ploder_evolved;
        newSpeed = 200;
        size = vector2(48, 48)*gb::getScale();
    }
};