#include "headers/allSprite.h"
#include <stdio.h>
Entity* AllSprite::enemyEntities[maxEnemyEntites];
Entity* AllSprite::levelEntities[maxLevelEntities];
Entity* AllSprite::player;
Entity** AllSprite::entities[maxEntities];

int AllSprite::init(){
    for(int i=0;i<maxEnemyEntites;i++){
        enemyEntities[i] = new Entity();
    }
    for(int i=0;i<maxLevelEntities;i++){
        levelEntities[i] = new Entity();
    }
    enemyEntities[0] = new MovableEntity(vector2(300,300), TEX_sprite_testBlock, COL_default);
    loadLevel(2);
    player = new Player(vector2(200, 200));
    
    for(int i=0;i<maxEntities;i++){
        entities[i] = new Entity*;
        *entities[i] = new Entity();
    }
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

void AllSprite::loadLevel(int index){
    vector<int>* level = Map::getLevel(index);
    int totalPixels = level->size();
    int mapWidth = level->at(0);
    int mapHeight = level->at(1);
    int pixelSizeW = gb::getWidth() / mapWidth;
    int pixelSizeH = gb::getHeight() / mapHeight; 
    int tmp = 0;
    for(int i=0;i<mapHeight;i++){
        for(int j=0;j<mapWidth;j++){
            int k = i*mapWidth+j+2;
            if(k > totalPixels - 2) continue;
            if(level->at(k) == 0) continue;
            vector2 pos = vector2(j*pixelSizeW,i*pixelSizeH);
            vector2 size = vector2(pixelSizeW, pixelSizeH);
            levelEntities[tmp] = new Entity(pos, TEX_sprite_testBlock, COL_default, size);
            tmp++;
        }
    }
}