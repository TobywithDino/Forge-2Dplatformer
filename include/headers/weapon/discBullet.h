#pragma once
#include "headers/weapon/projectile.h"

class DiscBullet : public Projectile{
public:
    DiscBullet() : Projectile(){}
    DiscBullet(vector2 pos, int speed, int damage) : Projectile(pos, speed, damage, TEX_projt_discBullet, COLBOX_projectile_discBullet){}
    void update() override{
        if(Collision::isColliding(collideBox, this, COL_level)) {
            hp -= 1;
            vel.x *= -1;
            if(hp == 0) {
                isActive = false;
                Projectile::setDiscBulletOut(false);
                return;
            }
            Sound::playSFX(SFX_weapon_disc_bounce);
            lastCollidedEntity = collidedEntity;
        }
        pos.x += vel.x * gb::getFrameTicks() / 1000;
        if(Collision::isColliding(collideBox, this, COL_enemy)) {
            if(lastCollidedEntity != collidedEntity){
                lastCollidedEntity = collidedEntity;
                collidedEntity->hurt(damage);
            }
        }else{
            lastCollidedEntity = this;
        }
        if(Collision::isColliding(collideBox, this, COL_player)){
            collidedEntity->hurt(damage);
        }
        Entity::update();
    }
private:
    int hp = 2;
    Entity* lastCollidedEntity = this;
};