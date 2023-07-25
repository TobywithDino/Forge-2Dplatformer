#include "headers/allSprite.h"
#include <stdio.h>
Entity* AllSprite::enemies[maxEnemies];
Entity* AllSprite::player;

int AllSprite::init(){
    for(int i=0;i<maxEnemies;i++) enemies[i] = new MovableEntity();
    player = new Player(vector2(200, 200));
    return 0;
}

void AllSprite::handleEvent(SDL_Event e){
    for(int i=0;i<maxEnemies;i++) enemies[i]->handleEvent(e);
    player->handleEvent(e);
}

void AllSprite::update(){
    for(int i=0;i<maxEnemies;i++) enemies[i]->update();
    player->update();
}

void AllSprite::render(){
    for(int i=0;i<maxEnemies;i++) enemies[i]->render();
    player->render();
}