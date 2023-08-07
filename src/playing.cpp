#include "headers/gameLoop/playing.h"

void Playing::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            AllSprite::handleEvent(event);
        }
    }
}
  
void Playing::update(){
    LevelSpawner::update();
    AllSprite::update(); //Game will set to GS_gameover when player is not active.
}

void Playing::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 200, 200, 200, 255);
    SDL_RenderClear(gb::getRenderer());
    AllSprite::render();
    SDL_RenderPresent(gb::getRenderer());
}