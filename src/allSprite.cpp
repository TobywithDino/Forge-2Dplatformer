#include "headers/allSprite.h"
Entity* AllSprite::enemyEntities[gb::maxEnemyEntities];
Entity* AllSprite::levelEntities[gb::maxLevelEntities];
Entity* AllSprite::player;
Entity** AllSprite::entities[gb::maxEntities];
int AllSprite::enemyIndex = 0;

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
    player = new Player();
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

    // for(int i=0;i<gb::maxEntities;i++){
    //     (*entities[i])->setEntites(entities);
    // }
    Entity::setEntities(entities);
    return 0;
}

void AllSprite::spawnEnemy(EnemyType type, vector2 pos){
    int tmp = 0;
    for(int i=0;i<gb::maxEnemyEntities;i++) if(enemyEntities[i]->getActive()) tmp++;
    if(tmp == gb::maxEnemyEntities) return;
    
    switch (type)
    {
    case ENEMY_crawler:
        enemyEntities[enemyIndex] = new Enemy(pos, TEX_sprite_crawler, COLBOX_crawler);
        break;
    default:
        printf("Error : AllSprite::spawnEnemy can't spawn correct type.\n");
        break;
    }
    enemyIndex++;
    enemyIndex %= gb::maxEnemyEntities;
}


void AllSprite::spawnPlayer(vector2 pos){
    player = new Player(pos);
}

void AllSprite::spawnLevel(int levelIndex){
    vector<vector<int>>* levelCollideBox = new vector<vector<int>>;
    switch (levelIndex)
    {
    case 0:
        levelCollideBox = CollideBox::getLevelCollideBox(COLBOX_level_1);
        break;
    case 1:
        levelCollideBox = CollideBox::getLevelCollideBox(COLBOX_level_2);
        break;
    default:
        break;
    }
    for(int i=0;i<levelCollideBox->size();i++){
        levelEntities[i] = new StaticEntity(&levelCollideBox->at(i));
    }
}

void AllSprite::clearEnemy(){
    for(int i=0;i<gb::maxEnemyEntities;i++){
        enemyEntities[i]->setActive(false);
    }
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