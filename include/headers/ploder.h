#pragma once
#include "headers/enemy.h"

class Ploder : public Enemy{
public:
    Ploder() : Enemy(){
    }
    Ploder(vector2 spawnPos) : Enemy(spawnPos, TEX_sprite_ploder, COLBOX_sprite_ploder){
        hp = 20;
        speed = 140;
        evolverType = TEX_sprite_ploder_evolved;
        newSpeed = 260;
        newHp = hp;
        size = vector2(48, 48) * gb::getScale();
        anim = Anim(&this->pos, TEX_sprite_crawler, ANIM_END, ANIM_ploder_walk, ANIM_END, size);
    }
};