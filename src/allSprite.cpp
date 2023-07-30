#include "headers/allSprite.h"
Entity* AllSprite::enemyEntities[gb::maxEnemyEntities];
Entity* AllSprite::levelEntities[gb::maxLevelEntities];
Entity* AllSprite::player;
Entity** AllSprite::entities[gb::maxEntities];
int AllSprite::enemyIndex = 0;
int AllSprite::levelIndex = 0;

int AllSprite::init(){
    // initialize level entities
    for(int i=0;i<gb::maxLevelEntities;i++){
        levelEntities[i] = new Entity();
        levelEntities[i]->setActive(false);
    }

    // initialize enemy entities
    for(int i=0;i<gb::maxEnemyEntities;i++){
        enemyEntities[i] = new Entity();
        enemyEntities[i]->setActive(false);
    }

    // initialize player entity
    player = new Entity();
    player->setActive(false);

    // initialize entities
    for(int i=0;i<gb::maxEntities;i++){
        entities[i] = new Entity*;
        *entities[i] = new Entity();
        (*entities[i])->setActive(false);
    }

    // link other game entities into entities
    int tmp = 0;
    for(int i=0;i<gb::maxLevelEntities;i++){
        entities[tmp] = &levelEntities[i];
        tmp++;
    }
    for(int i=0;i<gb::maxEnemyEntities;i++){
        entities[tmp] = &enemyEntities[i];
        tmp++;
    }
    for(int i=0;i<1;i++){
        entities[tmp] = &player;
        tmp++;
    }

    Entity::setEntities(entities);
    return 0;
}

void AllSprite::handleEvent(SDL_Event e){
    for(int i=0;i<gb::maxEntities;i++) (*entities[i])->handleEvent(e);
    for(int i=0;i<gb::maxEntities;i++) {
        CollideBox::handleEvent(e);
    }
}

void AllSprite::update(){
    for(int i=0;i<gb::maxEntities;i++) {
        (*entities[i])->update();
    }
}

void AllSprite::render(){
    for(int i=0;i<gb::maxEntities;i++) (*entities[i])->render();
    for(int i=0;i<gb::maxEntities;i++) {
        if((*entities[i])->getActive()){
            (*entities[i])->getCollideBox()->render();
        }
    }
}

void AllSprite::addEnemy(Entity* e){
    enemyEntities[enemyIndex] = e;
    enemyIndex++;
    enemyIndex %= gb::maxEnemyEntities;
}

void AllSprite::addLevelEntity(Entity* e){
    levelEntities[levelIndex] = e;
    levelIndex++;
    levelIndex %= gb::maxLevelEntities;
}

void AllSprite::addPlayer(Entity* e){
    player = e;
}

bool AllSprite::isEnemyFull(){
    int tmp = 0;
    for(int i=0;i<gb::maxEnemyEntities;i++){
        if(enemyEntities[i]->getActive()) tmp++;
    }
    if(tmp == gb::maxEnemyEntities) return true;
    else return false;
}