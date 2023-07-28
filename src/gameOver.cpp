#include "headers/gameLoop/gameOver.h"

void GameOver::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
    }
}

void GameOver::update(){

}

void GameOver::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 200, 200, 200, 255);
    SDL_RenderClear(gb::getRenderer());
    
    SDL_RenderPresent(gb::getRenderer());
}