#include "headers/levelSpawner.h"
vector2 LevelSpawner::playerSpawnPos = vector2(0,0);
vector<vector2> LevelSpawner::enemySpawnPos = {vector2(0,0)};
Uint64 LevelSpawner::spawnGapTicks = 200;
Uint64 LevelSpawner::nextSpawnTick = 0;
int LevelSpawner::ratio[ENEMY_END] = {0};
bool GameLoop::spawnedEntities = false;

void LevelSpawner::update(){
    LevelType levelType = Map::getLevelType();
    switch (levelType)
    {
    case LEV_1:
        playerSpawnPos = vector2(gb::getWidth()/2, 300);
        enemySpawnPos = {vector2(gb::getWidth()/2, -100)};
        spawnGapTicks = 2500 + (rand()%2000-1000);
        ratio[ENEMY_crawler] = 7;
        ratio[ENEMY_ploder] = 1;
        loadLevel();
        break;
    case LEV_2:
        playerSpawnPos = vector2(gb::getWidth()/2, 360);
        enemySpawnPos = {vector2(gb::getWidth()/2, -100)};
        spawnGapTicks = 2000 + (rand()%2000-1000);
        ratio[ENEMY_crawler] = 5;
        ratio[ENEMY_ploder] = 2;
        loadLevel();
        break;
    case LEV_3:
        playerSpawnPos = vector2(gb::getWidth()/2, 300);
        enemySpawnPos = {vector2(gb::getWidth()/2, -100)};
        spawnGapTicks = 2000 + (rand()%2000-1000);
        ratio[ENEMY_crawler] = 5;
        ratio[ENEMY_ploder] = 2;
        loadLevel();
        break;
    default:
        printf("Error: LevelSpawner can't spawn level: %d\n", levelType);
        break;
    }
}

void LevelSpawner::loadLevel(){
    if(!GameLoop::spawnedEntities){
        AllSprite::clearEntities();
        spawnLevelEntities();
        spawnPlayer(playerSpawnPos);
        GameLoop::spawnedEntities = true;
    }
    if(SDL_GetTicks64() >= nextSpawnTick){
        nextSpawnTick = SDL_GetTicks64() + spawnGapTicks;
        spawnEnemy(enemySpawnPos[rand()%enemySpawnPos.size()], ratio);
    }
    spawnWeaponBox();
}

void LevelSpawner::spawnLevelEntities(){
    vector<vector<int>>* levelCollideBox = new vector<vector<int>>;
    LevelType levelType = Map::getLevelType();
    levelCollideBox = CollideBox::getLevelCollideBox(levelType);
    for(int i=0;i<levelCollideBox->size();i++){
        AllSprite::addLevelEntity(new StaticEntity(&levelCollideBox->at(i)));
    }
}

void LevelSpawner::spawnPlayer(vector2 pos){
    Player *p = new Player(pos);
    AllSprite::addPlayer(p);
}

void LevelSpawner::spawnEnemy(vector2 pos, int ratio[]){
    // make enemy type dice for spawning
    vector<EnemyType> typeDice;
    for(EnemyType i=ENEMY_crawler;i<ENEMY_END;i = (EnemyType)(i+1)){
        for(int j=0;j<ratio[i];j++){
            typeDice.push_back(i);
        }
    }
    // roll the dice to decide which enemy to spawn
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

void LevelSpawner::spawnWeaponBox(){
    if(AllSprite::isWeaponBoxFull()) return;
    vector2 tmpPos = vector2(rand()%(gb::getWidth()-50) + 50, rand()%(gb::getHeight()-150) + 50);
    CollideBox tmpBox = CollideBox(COLBOX_sprite_weaponBox, &tmpPos, COL_weaponBox);
    while(  Collision::isColliding(tmpBox, new Entity(), COL_level) ||
            Collision::getDistance(tmpBox) < 500)
    {   
        tmpPos = vector2(rand()%(gb::getWidth()-50) + 50, rand()%(gb::getHeight()-150) + 50);
        tmpBox = CollideBox(COLBOX_sprite_weaponBox, &tmpPos, COL_weaponBox);
    }
    Entity* e = new WeaponBox(tmpPos);
    AllSprite::addWeaponBox(e);
}