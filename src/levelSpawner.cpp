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
        playerSpawnPos = vector2(gb::getWidth()/2, 50);
        spawnGapTicks = 200;
        spawnLevel();
        break;
    case 1:
        playerSpawnPos = vector2(gb::getWidth()/2, 50);
        spawnGapTicks = 200;
        spawnLevel();
        break;
    default:
        printf("Error: LevelSpawner can't spawn level: %d\n", levelIndex);
        break;
    }
}

void LevelSpawner::spawnLevel(){
    if(!GameLoop::spawnedLevel){
        AllSprite::spawnLevel(gb::getLevelIndex());
        GameLoop::spawnedLevel = true;
    }
    if(!GameLoop::spawnedPlayer){
        AllSprite::spawnPlayer(playerSpawnPos);
        GameLoop::spawnedPlayer = true;
    }
    if(!GameLoop::spawnedEnemy){
        AllSprite::clearEnemy();
        GameLoop::spawnedEnemy = true;
    }
    if(SDL_GetTicks64() >= nextSpawnTick){
        nextSpawnTick = SDL_GetTicks64() + spawnGapTicks;
        vector2 enemySpawnPos(gb::getWidth()/2, -100);
        AllSprite::spawnEnemy(ENEMY_crawler, enemySpawnPos);
    }
}