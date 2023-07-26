#include "headers/allSprite.h"
#include <stdio.h>
Entity* AllSprite::enemyEntities[maxEnemyEntites];
Entity* AllSprite::levelEntities[maxLevelEntities];
Entity* AllSprite::player;
Entity** AllSprite::entities[maxEntities];

int AllSprite::init(){
    // initial other game entities
    for(int i=0;i<maxEnemyEntites;i++){
        enemyEntities[i] = new Entity();
    }
    for(int i=0;i<maxLevelEntities;i++){
        levelEntities[i] = new Entity();
    }
    enemyEntities[0] = new MovableEntity(vector2(280,300), TEX_sprite_testBlock, COL_default);
    loadLevelEntities(gb::getLevelIndex());
    player = new Player(vector2(200, 200));
    
    // initial entities
    for(int i=0;i<maxEntities;i++){
        entities[i] = new Entity*;
        *entities[i] = new Entity();
    }

    // link other game entities into entities
    int tmp = 0;
    for(int i=0;i<maxEnemyEntites;i++){
        *entities[tmp] = enemyEntities[i];
        tmp++;
    }
    for(int i=0;i<maxLevelEntities;i++){
        *entities[tmp] = levelEntities[i];
        tmp++;
    }
    for(int i=0;i<1;i++){
        *entities[tmp] = player;
        tmp++;
    }
    return 0;
}

void AllSprite::handleEvent(SDL_Event e){
    // for(int i=0;i<maxEnemyEntites;i++) enemyEntities[i]->handleEvent(e);
    // player->handleEvent(e);
    for(int i=0;i<maxEntities;i++) (*entities[i])->handleEvent(e);
}

void AllSprite::update(){
    // for(int i=0;i<maxEnemyEntites;i++) enemyEntities[i]->update();
    // player->update();
    for(int i=0;i<maxEntities;i++) (*entities[i])->update();
    checkCollide();
}

void AllSprite::render(){
    // for(int i=0;i<maxEnemyEntites;i++) enemyEntities[i]->render();
    // player->render();
    for(int i=0;i<maxEntities;i++) (*entities[i])->render();
}

void AllSprite::checkCollide(){
    for(int i=0;i<maxEntities;i++){
        for(int j=0;j<maxEntities;j++){
            Entity* a = *entities[i];
            Entity* b = *entities[j];
            if(a == b) continue;
            CollideBox* aBox = a->getCollideBox();
            CollideBox* bBox = b->getCollideBox();
            if( aBox->getBoxLeft() < bBox->getBoxRight() && 
                aBox->getBoxRight() > bBox->getBoxLeft())
            {
                aBox->setIsCollidedHorizontal(true);
                bBox->setIsCollidedHorizontal(true);
            }else
            {
                aBox->setIsCollidedHorizontal(false);
                bBox->setIsCollidedHorizontal(false);
            }
            if( aBox->getBoxTop() < bBox->getBoxDown() && 
                aBox->getBoxDown() > bBox->getBoxTop())
            {
                aBox->setIsCollidedVertical(true);
                bBox->setIsCollidedVertical(true);
            }else
            {
                aBox->setIsCollidedVertical(false);
                bBox->setIsCollidedVertical(false);
            }
        }
    }
}

void AllSprite::loadLevelEntities(int index){
    vector<vector<int>>* levelCollideBox = new vector<vector<int>>;
    switch (index)
    {
    case 0:
        levelCollideBox = CollideBox::getLevelCollideBox(COL_level_1);
        break;
    case 1:
        levelCollideBox = CollideBox::getLevelCollideBox(COL_level_2);
        break;
    default:
        break;
    }
    for(int i=0;i<levelCollideBox->size();i++){
        levelEntities[i] = new StaticEntity(&levelCollideBox->at(i));
    }
}