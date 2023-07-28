#include "headers/enemy.h"

Enemy::Enemy() : MovableEntity(vector2(0,0), TEX_sprite_testBlock, COLBOX_default, COL_enemy){
    speed = 180;
    vel.x = speed;
}
Enemy::Enemy(vector2 pos, TextureType tType, CollideBoxType cbType) : MovableEntity(pos, tType, cbType, COL_enemy){
    speed = 180;
    vel.x = speed;
}

void Enemy::update(){
    MovableEntity::update();
    CollideBox tmpBox = collideBox;
    tmpBox.setPos(new vector2(pos.x+vel.x*gb::getFrameTicks()/1000, pos.y));
    if(Collision::isColliding(tmpBox, this, COL_level)) vel.x *= -1;
}