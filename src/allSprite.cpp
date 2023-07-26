#include "headers/allSprite.h"
#include <stdio.h>
Entity* AllSprite::enemyEntities[maxEnemyEntities];
Entity* AllSprite::levelEntities[maxLevelEntities];
Entity* AllSprite::player;
Entity** AllSprite::entities[maxEntities];

int AllSprite::init(){
    // initial other game entities
    for(int i=0;i<maxEnemyEntities;i++){
        enemyEntities[i] = new Entity();
        enemyEntities[i]->setActive(false);
    }
    for(int i=0;i<maxLevelEntities;i++){
        levelEntities[i] = new Entity();
        levelEntities[i]->setActive(false);
    }
    // enemyEntities[0] = new MovableEntity(vector2(0,300), TEX_sprite_testBlock, COL_default);
    // enemyEntities[1] = new MovableEntity(vector2(48,300), TEX_sprite_testBlock, COL_default);
    // enemyEntities[2] = new MovableEntity(vector2(480,300), TEX_sprite_testBlock, COL_default);
    // for(int i=0;i<22;i++){
    //     enemyEntities[i] = new MovableEntity(vector2(48*i,300), TEX_sprite_testBlock, COL_default);
    // }

    loadLevelEntities(gb::getLevelIndex());
    player = new Player(vector2(480, 0));
    
    // initial entities
    for(int i=0;i<maxEntities;i++){
        entities[i] = new Entity*;
        *entities[i] = new Entity();
        (*entities[i])->setActive(false);
    }

    // link other game entities into entities
    int tmp = 0;
    for(int i=0;i<maxLevelEntities;i++){
        *entities[tmp] = levelEntities[i];
        tmp++;
    }
    for(int i=0;i<maxEnemyEntities;i++){
        *entities[tmp] = enemyEntities[i];
        tmp++;
    }
    for(int i=0;i<1;i++){
        *entities[tmp] = player;
        tmp++;
    }
    return 0;
}

void AllSprite::handleEvent(SDL_Event e){
    for(int i=0;i<maxEntities;i++) (*entities[i])->handleEvent(e);
}

void AllSprite::update(){
    for(int i=0;i<maxEntities;i++) (*entities[i])->update();
    checkCollide();
}

void AllSprite::render(){
    for(int i=0;i<maxEntities;i++) (*entities[i])->render();
}

void AllSprite::checkCollide(){
    Entity *a, *b;

    for(int i=0;i<maxEntities;i++){
        a = *entities[i];
        bool isOnGroundAgain = false;
        if(!a->getActive()) continue;
        for(int j=0;j<maxEntities;j++){
            b = *entities[j];
            if(!b->getActive()) continue;
            // if(a == player) printf("%d: %f\n", j, a->getCollideBox()->getBoxDown());
            if(a == b) continue;
            CollideBox* aBox = a->getCollideBox();
            CollideBox* bBox = b->getCollideBox();
            bool collided = false;
            if( aBox->getBoxLeft() < bBox->getBoxRight() && 
                aBox->getBoxRight() > bBox->getBoxLeft() &&
                aBox->getBoxTop() < bBox->getBoxDown() && 
                aBox->getBoxDown() > bBox->getBoxTop())
            {
                if(abs(a->getVel().x) < abs(b->getVel().x)) continue;
                if(a->getVel().x > 0){
                    a->setPos(vector2(bBox->getBoxLeft() - aBox->getBoxOffset().x - aBox->getBoxSize().x, a->getPos().y));
                    a->setVel(vector2(0, a->getVel().y));
                } 
                if(a->getVel().x < 0){
                    a->setPos(vector2(bBox->getBoxRight() - aBox->getBoxOffset().x, a->getPos().y));
                    a->setVel(vector2(0, a->getVel().y));
                }
            }

            // check if a is on ground again. 'a->getVel.y == 0' is to check if the player is jumping or not
            if(a->getIsOnGround() && !isOnGroundAgain && a->getVel().y == 0){
                Entity tmp = *a;
                a = &tmp;
                a->setPos(vector2(a->getPos().x, a->getPos().y+1));
                a->setVel(vector2(a->getVel().x, 1));
            }

            if( aBox->getBoxLeft() < bBox->getBoxRight() && 
                aBox->getBoxRight() > bBox->getBoxLeft() &&
                aBox->getBoxTop() < bBox->getBoxDown() && 
                aBox->getBoxDown() > bBox->getBoxTop())
            {
                if(abs(a->getVel().y) < abs(b->getVel().y)) continue;
                    
                if(a->getVel().y > 0){
                    a->setPos(vector2(a->getPos().x, bBox->getBoxTop() - aBox->getBoxOffset().y - aBox->getBoxSize().y));
                    a->setVel(vector2(a->getVel().x, 0));
                    a->setIsOnGround(true);
                    isOnGroundAgain = true;
                }
                if(a->getVel().y < 0){
                    a->setPos(vector2(a->getPos().x, bBox->getBoxDown() - aBox->getBoxOffset().y));
                    a->setVel(vector2(a->getVel().x, 0));
                }
            }else{
                if(!isOnGroundAgain && a->getIsOnGround()){
                    a->setIsOnGround(false);
                } 
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