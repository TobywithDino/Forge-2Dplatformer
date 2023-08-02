#pragma once
#include "headers/enemy.h"

class Crawler : public Enemy{
public:
    Crawler() : Enemy(){
    }
    
    Crawler(vector2 spawnPos) : Enemy(spawnPos, TEX_sprite_crawler, COLBOX_sprite_crawler){
        hp = 8;
        speed = 120;
        evolverType = TEX_sprite_crawler_evolved;
        newSpeed = 220;
        newHp = hp;
    }
};