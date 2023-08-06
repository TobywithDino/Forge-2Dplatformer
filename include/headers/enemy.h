#pragma once
#include "headers/movableEntity.h"

enum EnemyType{
    ENEMY_crawler,
    ENEMY_ploder,
    ENEMY_END
};

class Enemy : public MovableEntity{
public:
    Enemy();
    Enemy(vector2 spawnPos, TextureType tType, CollideBoxType cbType);
    virtual void update() override;
private:
    vector2 spawnPos = vector2(0,0);
    bool evolved = false;
    void evolve(TextureType tType, double newSpeed);
    void hurt(int damage) override{
        this->hp -= damage;
        if(hp > 0) Sound::playSFX(SFX_enemy_hurt);
        else Sound::playSFX(SFX_enemy_dead);
    }
protected:
    TextureType evolverType = TEX_sprite_testBlock;
    int newHp = 1;
    double newSpeed = 200;
    Anim evolvedAnim = Anim();
};