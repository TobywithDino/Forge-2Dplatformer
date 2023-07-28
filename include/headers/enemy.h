#pragma once
#include "headers/movableEntity.h"

enum EnemyType{
    ENEMY_crawler
};

class Enemy : public MovableEntity{
public:
    Enemy();
    Enemy(vector2 spawnPos, TextureType tType, CollideBoxType cbType);
    void update() override;
private:
    vector2 spawnPos = vector2(0,0);
protected:
    int hp = 1;
};