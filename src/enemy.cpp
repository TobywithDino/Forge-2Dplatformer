#include "headers/enemy.h"

Enemy::Enemy() : MovableEntity(vector2(0,0), TEX_sprite_testBlock, COLBOX_default, COL_enemy){
    speed = 180;
    vel.x = speed;
}
Enemy::Enemy(vector2 spawnPos, TextureType tType, CollideBoxType cbType) : MovableEntity(spawnPos, tType, cbType, COL_enemy){
    this->spawnPos = spawnPos;
    speed = 180;
    vel.x = speed;
}

void Enemy::update(){
    if(hp <= 0) isActive = false;

    CollideBox tmpBox = collideBox;
    tmpBox.setPos(new vector2(pos.x+vel.x*gb::getFrameTicks()/1000, pos.y));
    if(Collision::isColliding(tmpBox, this, COL_level)) vel.x *= -1;
    
    if(pos.y > gb::getHeight()){
        pos = spawnPos;
        vel.y = 0;
    }

    MovableEntity::update();
}