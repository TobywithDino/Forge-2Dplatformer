#include "headers/levelSpawner.h"
vector2 LevelSpawner::playerSpawnPos = vector2(0,0);
Uint64 LevelSpawner::spawnGapTicks = 200;
Uint64 LevelSpawner::nextSpawnTick = 0;
bool GameLoop::spawnedPlayer = false;
bool GameLoop::spawnedLevel = false;
bool GameLoop::spawnedEnemy = false;

void LevelSpawner::update(int levelIndex){
    switch (levelIndex)
    {
    case 0:
        spawnLevel1();
        break;
    default:
        printf("Error: LevelSpawner can't spawn enemy\n");
        break;
    }
}

void LevelSpawner::spawnLevel1(){
    if(!GameLoop::spawnedLevel){
        AllSprite::spawnLevel(gb::getLevelIndex());
        GameLoop::spawnedLevel = true;
    }
    if(!GameLoop::spawnedPlayer){
        playerSpawnPos = vector2(gb::getWidth()/2, 50);
        AllSprite::spawnPlayer(playerSpawnPos);
        GameLoop::spawnedPlayer = true;
    }
    if(!GameLoop::spawnedEnemy){
        AllSprite::clearEnemy();
        GameLoop::spawnedEnemy = true;
    }
    if(SDL_GetTicks64() >= nextSpawnTick){
        nextSpawnTick = SDL_GetTicks64() + spawnGapTicks;
        vector2 enemySpawnPos(gb::getWidth()/2, -50);
        AllSprite::spawnEnemy(ENEMY_crawler, enemySpawnPos);
    }
}