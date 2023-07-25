#include "headers/allSprite.h"
#include <stdio.h>

vector<MovableEntity*>* AllSprite::entities;
MovableEntity* AllSprite::player;

int AllSprite::init(){
    entities = new vector<MovableEntity*>;
    
    MovableEntity* e;
    e = new MovableEntity(vector2(300, 200), TEX_sprite_testBlock, COL_default);
    entities->push_back(e);

    player = new Player(vector2(200, 200));
    return 0;
}