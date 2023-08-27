#pragma once
#include "headers/enemy.h"

class Crawler : public Enemy{
public:
    Crawler() : Enemy(){
    }
    
    Crawler(vector2 spawnPos) : Enemy(spawnPos, TEX_sprite_crawler, COLBOX_sprite_crawler){
        hp = 8;
        speed = 220;
        evolverType = TEX_sprite_crawler_evolved;
        newSpeed = 300;
        newHp = hp;
        anim = Anim(&this->pos, TEX_sprite_crawler, ANIM_END, ANIM_crawler_walk, ANIM_END);
        evolvedAnim = Anim(&this->pos, TEX_sprite_crawler_evolved, ANIM_END, ANIM_crawler_evolved_walk, ANIM_END);
    }
};