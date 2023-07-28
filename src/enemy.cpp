#include "headers/enemy.h"

Enemy::Enemy() : MovableEntity(vector2(0,0), TEX_sprite_testBlock, COLBOX_default, COL_enemy){
}
Enemy::Enemy(vector2 pos, TextureType tType, CollideBoxType cbType) : MovableEntity(pos, tType, cbType, COL_enemy){

}