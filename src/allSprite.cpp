#include "headers/allSprite.h"
Entity* AllSprite::enemyEntities[gb::maxEnemyEntities];
Entity* AllSprite::levelEntities[gb::maxLevelEntities];
Entity* AllSprite::projtEntities[gb::maxProjtEntities];
Entity* AllSprite::weaponBox;
Entity* AllSprite::player;
Entity** AllSprite::entities[gb::maxEntities];
int AllSprite::enemyIndex = 0;
int AllSprite::levelIndex = 0;
int AllSprite::projtIndex = 0;

int AllSprite::init(){
    // initialize level entities
    clearLevel();
    // initialize enemy entities
    clearEnemy();
    // initialize projectile entities
    clearProjt();
    // initialzie weaponBox entities
    clearWeaponBox();
    // initialize player entity
    clearPlayer();
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
    for(int i=0;i<gb::maxProjtEntities;i++){
        entities[tmp] = &projtEntities[i];
        tmp++;
    }
    for(int i=0;i<1;i++){
        entities[tmp] = &weaponBox;
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
    for(int i=0;i<gb::maxEntities;i++){
        if((*entities[i])->getActive()){
            (*entities[i])->handleEvent(e);
        }
    }
    CollideBox::handleEvent(e);
}

void AllSprite::update(){
    for(int i=0;i<gb::maxEntities;i++) {
        if((*entities[i])->getActive()){
            (*entities[i])->update();
        }
    }
    if(!player->getActive()){
        gb::setGameState(GS_GameOver);
    }
}

void AllSprite::render(){
    for(int i=0;i<gb::maxEntities;i++){
        if((*entities[i])->getActive()){
            (*entities[i])->render();
        }
    }
    for(int i=0;i<gb::maxEntities;i++) {
        if((*entities[i])->getActive()){
            (*entities[i])->getCollideBox()->render();
        }
    }
}

void AllSprite::addEnemy(Entity* e){
    if(isEnemyFull()) return;
    enemyEntities[enemyIndex] = e;
    enemyIndex++;
    enemyIndex %= gb::maxEnemyEntities;
}

void AllSprite::addLevelEntity(Entity* e){
    levelEntities[levelIndex] = e;
    levelIndex++;
    levelIndex %= gb::maxLevelEntities;
}

void AllSprite::addProjt(Entity* e){
    if(isProjtFull()) return;
    projtEntities[projtIndex] = e;
    projtIndex++;
    projtIndex %= gb::maxProjtEntities;
}

void AllSprite::addWeaponBox(Entity* e){
    if(isWeaponBoxFull()) return;
    weaponBox = e;
}

void AllSprite::addPlayer(Entity* e){
    player = e;
}

void AllSprite::clearEnemy(){
    for(int i=0;i<gb::maxEnemyEntities;i++){
        enemyEntities[i] = new Entity();
        enemyEntities[i]->setActive(false);
    }
    enemyIndex = 0;
}

void AllSprite::clearLevel(){
    for(int i=0;i<gb::maxLevelEntities;i++){
        levelEntities[i] = new Entity();
        levelEntities[i]->setActive(false);
    }
    levelIndex = 0;
}

void AllSprite::clearProjt(){
    for(int i=0;i<gb::maxProjtEntities;i++){
        projtEntities[i] = new Entity();
        projtEntities[i]->setActive(false);
    }
    projtIndex = 0;
}

void AllSprite::clearWeaponBox(){
    weaponBox = new Entity();
    weaponBox->setActive(false);
}

void AllSprite::clearPlayer(){
    player = new Entity();
    player->setActive(false);
}

bool AllSprite::isEnemyFull(){
    int tmp = 0;
    for(int i=0;i<gb::maxEnemyEntities;i++){
        if(enemyEntities[i]->getActive()) tmp++;
    }
    if(tmp == gb::maxEnemyEntities) return true;
    else return false;
}

bool AllSprite::isProjtFull(){
    int tmp = 0;
    for(int i=0;i<gb::maxProjtEntities;i++){
        if(projtEntities[i]->getActive()) tmp++;
    }
    if(tmp == gb::maxProjtEntities) return true;
    else return false;
}

bool AllSprite::isWeaponBoxFull(){
    if(weaponBox->getActive()) return true;
    else return false;
}