#include "headers/levelSpawner.h"
vector2 LevelSpawner::playerSpawnPos = vector2(0,0);
vector2 LevelSpawner::enemySpawnPos = vector2(0,0);
Uint64 LevelSpawner::spawnGapTicks = 200;
Uint64 LevelSpawner::nextSpawnTick = 0;
int LevelSpawner::ratio[ENEMY_END] = {0};
bool GameLoop::spawnedPlayer = false;
bool GameLoop::spawnedLevel = false;
bool GameLoop::spawnedEnemy = false;

void LevelSpawner::update(){
    LevelType levelType = Map::getLevelType();
    switch (levelType)
    {
    case LEV_1:
        playerSpawnPos = vector2(gb::getWidth()/2, 300);
        enemySpawnPos = vector2(gb::getWidth()/2, -100);
        spawnGapTicks = 3000;
        ratio[ENEMY_crawler] = 7;
        ratio[ENEMY_ploder] = 1;
        loadLevel();
        break;
    case LEV_2:
        playerSpawnPos = vector2(gb::getWidth()/2, 50);
        enemySpawnPos = vector2(gb::getWidth()/2, -100);
        spawnGapTicks = 5000;
        ratio[ENEMY_crawler] = 10;
        ratio[ENEMY_ploder] = 3;
        loadLevel();
        break;
    default:
        printf("Error: LevelSpawner can't spawn level: %d\n", levelType);
        break;
    }
}

void LevelSpawner::loadLevel(){
    if(!GameLoop::spawnedLevel){
        clearLevel();
        spawnLevelEntities();
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
        spawnEnemy(enemySpawnPos, ratio);
    }
}

void LevelSpawner::spawnLevelEntities(){
    vector<vector<int>>* levelCollideBox = new vector<vector<int>>;
    LevelType levelType = Map::getLevelType();
    switch (levelType)
    {
    case LEV_1:
        levelCollideBox = CollideBox::getLevelCollideBox(COLBOX_level_1);
        break;
    case LEV_2:
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

void LevelSpawner::spawnEnemy(vector2 pos, int ratio[]){
    vector<EnemyType> typeDice;
    for(EnemyType i=ENEMY_crawler;i<ENEMY_END;i = (EnemyType)(i+1)){
        for(int j=0;j<ratio[i];j++){
            typeDice.push_back(i);
        }
    }
    EnemyType type = typeDice[rand()%typeDice.size()];

    Entity* e = new Entity();
    switch (type)
    {
    case ENEMY_crawler:
        e = new Crawler(pos);
        break;
    case ENEMY_ploder:
        e = new Ploder(pos);
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