#include "headers/gameLoop/gameOver.h"

void GameOver::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.scancode == SDL_SCANCODE_Z){
                    gb::setGameState(GS_Menu);
                    spawnedEntities = false;
                }
            }
        }
    }
}

void GameOver::update(){

}

void GameOver::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 50, 50, 50, 255);
    SDL_RenderClear(gb::getRenderer());
    
    SDL_RenderPresent(gb::getRenderer());
}