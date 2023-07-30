#include "headers/levelSpawner.h"
vector2 LevelSpawner::playerSpawnPos = vector2(0,0);
vector2 LevelSpawner::enemySpawnPos = vector2(0,0);
Uint64 LevelSpawner::spawnGapTicks = 200;
Uint64 LevelSpawner::nextSpawnTick = 0;
bool GameLoop::spawnedPlayer = false;
bool GameLoop::spawnedLevel = false;
bool GameLoop::spawnedEnemy = false;

void LevelSpawner::update(int levelIndex){
    switch (levelIndex)
    {
    case 0:
        playerSpawnPos = vector2(gb::getWidth()/2, 300);
        enemySpawnPos = vector2(gb::getWidth()/2, -100);
        spawnGapTicks = 200;
        loadLevel();
        break;
    case 1:
        playerSpawnPos = vector2(gb::getWidth()/2, 50);
        enemySpawnPos = vector2(gb::getWidth()/2, -100);
        spawnGapTicks = 5000;
        loadLevel();
        break;
    default:
        printf("Error: LevelSpawner can't spawn level: %d\n", levelIndex);
        break;
    }
}

void LevelSpawner::loadLevel(){
    if(!GameLoop::spawnedLevel){
        clearLevel();
        spawnLevelEntities(gb::getLevelIndex());
        GameLoop::spawnedLevel = true;
    }
    if(!GameLoop::spawnedPlayer){
        spawnPlayer(playerSpawnPos);
        GameLoop::spawnedPlayer = true;
    }
    if(!GameLoop::spawnedEnemy){
        clearEnemy();
        GameLoop::spawnedEnemy = true;
    }
    if(SDL_GetTicks64() >= nextSpawnTick){
        nextSpawnTick = SDL_GetTicks64() + spawnGapTicks;
        spawnEnemy(ENEMY_crawler, enemySpawnPos);
    }
}

void LevelSpawner::spawnLevelEntities(int levelIndex){
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
        AllSprite::addLevelEntity(new StaticEntity(&levelCollideBox->at(i)));
    }
}

void LevelSpawner::spawnPlayer(vector2 pos){
    Player *p = new Player(pos);
    AllSprite::addPlayer(p);
}

void LevelSpawner::spawnEnemy(EnemyType type, vector2 pos){
    if(AllSprite::isEnemyFull()) return;

    Entity* e = new Entity();
    switch (type)
    {
    case ENEMY_crawler:
        e = new Enemy(pos, TEX_sprite_crawler, COLBOX_crawler);
        break;
    default:
        printf("Error : AllSprite::spawnEnemy can't spawn correct type.\n");
        break;
    }
    AllSprite::addEnemy(e);
}

void LevelSpawner::clearEnemy(){
    for(int i=0;i<gb::maxEnemyEntities;i++){
        Entity *e = new Entity();
        e->setActive(false);
        AllSprite::addEnemy(e);
    }
}

void LevelSpawner::clearLevel(){
    for(int i=0;i<gb::maxLevelEntities;i++){
        Entity *e = new Entity();
        e->setActive(false);
        AllSprite::addLevelEntity(e);
    }
}