#include "headers/enemy.h"

Enemy::Enemy() : MovableEntity(vector2(0,0), TEX_sprite_testBlock, COLBOX_default, COL_enemy){
    speed = 130;
    if(rand()%2) vel.x = speed;
    else vel.x = -speed;
    evolverType = TEX_sprite_testBlock;
    newSpeed = speed;
}
Enemy::Enemy(vector2 spawnPos, TextureType tType, CollideBoxType cbType) : MovableEntity(spawnPos, tType, cbType, COL_enemy){
    this->spawnPos = spawnPos;
    speed = 130;
    if(rand()%2) vel.x = speed;
    else vel.x = -speed;
    evolverType = tType;
    newSpeed = speed;
}

void Enemy::update(){
    CollideBox tmpBox = collideBox;
    tmpBox.setPos(new vector2(pos.x+vel.x*gb::getFrameTicks()/1000, pos.y));
    if(Collision::isColliding(tmpBox, this, COL_level)) vel.x *= -1;
    
    if(pos.y > gb::getHeight()){
        evolve(evolverType, newSpeed);
        pos = spawnPos;
        vel.y = 0;
        if(rand()%2) vel.x = speed;
        else vel.x = -speed;
    }

    MovableEntity::update();
}

void Enemy::evolve(TextureType tType, double newSpeed){
    speed = newSpeed;
    setTexture(tType);
}