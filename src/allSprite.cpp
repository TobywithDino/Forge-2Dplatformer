#include "headers/allSprite.h"
#include <stdio.h>
Entity* AllSprite::enemyEntities[gb::maxEnemyEntities];
Entity* AllSprite::levelEntities[gb::maxLevelEntities];
Entity* AllSprite::player;
Entity** AllSprite::entities[gb::maxEntities];

int AllSprite::init(){
    // initial other game entities
    for(int i=0;i<gb::maxEnemyEntities;i++){
        enemyEntities[i] = new Entity();
        enemyEntities[i]->setActive(false);
    }
    
    for(int i=0;i<gb::maxLevelEntities;i++){
        levelEntities[i] = new Entity();
        levelEntities[i]->setActive(false);
    }
    // enemyEntities[0] = new MovableEntity(vector2(480-48,200), TEX_sprite_testBlock, COL_default);
    // enemyEntities[1] = new MovableEntity(vector2(480,200), TEX_sprite_testBlock, COL_default);
    enemyEntities[2] = new MovableEntity(vector2(480,350), TEX_sprite_testBlock, COL_default);

    loadLevelEntities(gb::getLevelIndex());
    player = new Player(vector2(480-48, 350));
    
    // initial entities
    for(int i=0;i<gb::maxEntities;i++){
        entities[i] = new Entity*;
        *entities[i] = new Entity();
        (*entities[i])->setActive(false);
    }

    // link other game entities into entities
    int tmp = 0;
    for(int i=0;i<gb::maxLevelEntities;i++){
        *entities[tmp] = levelEntities[i];
        tmp++;
    }
    for(int i=0;i<gb::maxEnemyEntities;i++){
        *entities[tmp] = enemyEntities[i];
        tmp++;
    }
    for(int i=0;i<1;i++){
        *entities[tmp] = player;
        tmp++;
    }
    for(int i=0;i<gb::maxEntities;i++){
        (*entities[i])->setEntites(entities);
    }
    return 0;
}

void AllSprite::handleEvent(SDL_Event e){
    for(int i=0;i<gb::maxEntities;i++) (*entities[i])->handleEvent(e);
    for(int i=0;i<gb::maxEntities;i++) {
        if((*entities[i])->getActive()){
            (*entities[i])->getCollideBox()->handleEvent(e);
        }
    }
}

void AllSprite::update(){
    for(int i=0;i<gb::maxEntities;i++) (*entities[i])->update();
}

void AllSprite::render(){
    for(int i=0;i<gb::maxEntities;i++) (*entities[i])->render();
    for(int i=0;i<gb::maxEntities;i++) {
        if((*entities[i])->getActive()){
            (*entities[i])->getCollideBox()->render();
        }
    }
}

/* about to dump them
void AllSprite::collision(){
    Entity *a, *b;
    for(int i=0;i<maxEntities;i++){
        a = *entities[i];
        bool isOnGroundAgain = false; 
        if(!a->getActive()) continue;
        for(int j=0;j<maxEntities;j++){
            b = *entities[j];
            if(!b->getActive()) continue;
            if(a == b) continue;

            if(collided(a, b)){
                blockH(a, b);
            }
            if(collided(a, b)){
                blockV(a, b);
            }
            // check if a is on ground again. 'a->getVel.y == 0' is to check if the player is jumping or not
            if(a->getIsOnGround() && !isOnGroundAgain && a->getVel().y == 0){
                if(onGroundAgain(*a, *b)){
                    isOnGroundAgain = true;
                }else{
                    a->setIsOnGround(false);
                }
            }

        }
    }
}

bool AllSprite::collided(Entity *a, Entity *b){
    CollideBox* aBox = a->getCollideBox();
    CollideBox* bBox = b->getCollideBox();
    if( aBox->getBoxLeft() < bBox->getBoxRight() && 
        aBox->getBoxRight() > bBox->getBoxLeft() &&
        aBox->getBoxTop() < bBox->getBoxDown() && 
        aBox->getBoxDown() > bBox->getBoxTop())
    {
        return true;
    }
    return false;
}

void AllSprite::blockH(Entity *a, Entity *b){
    CollideBox* aBox = a->getCollideBox();
    CollideBox* bBox = b->getCollideBox();
    if(a->getVel().x > 0){
        a->setPos(vector2(bBox->getBoxLeft() - aBox->getBoxOffset().x - aBox->getBoxSize().x, a->getPos().y));
        a->setVel(vector2(0, a->getVel().y));
    } 
    if(a->getVel().x < 0){
        a->setPos(vector2(bBox->getBoxRight() - aBox->getBoxOffset().x, a->getPos().y));
        a->setVel(vector2(0, a->getVel().y));
    }   
}

void AllSprite::blockV(Entity *a, Entity *b){
    CollideBox* aBox = a->getCollideBox();
    CollideBox* bBox = b->getCollideBox();
           
    if(a->getVel().y > 0){
        a->setPos(vector2(a->getPos().x, bBox->getBoxTop() - aBox->getBoxOffset().y - aBox->getBoxSize().y));
        a->setVel(vector2(a->getVel().x, 0));
        a->setIsOnGround(true);
    }
    if(a->getVel().y < 0){
        a->setPos(vector2(a->getPos().x, bBox->getBoxDown() - aBox->getBoxOffset().y));
        a->setVel(vector2(a->getVel().x, 0));
    }
}

bool AllSprite::onGroundAgain(Entity tmp_a, Entity tmp_b){
    tmp_a.getCollideBox()->setPos(new vector2(tmp_a.getPos().x, tmp_a.getPos().y+1));
    if(collided(&tmp_a, &tmp_b)){
        return true;
    }
    return false;
}
*/


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