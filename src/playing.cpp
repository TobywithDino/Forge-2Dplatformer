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
    t->update(std::to_string(gb::getScore()));
}

void Playing::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 200, 200, 200, 255);
    SDL_RenderClear(gb::getRenderer());
    AllSprite::render();
    t->render();
    SDL_RenderPresent(gb::getRenderer());
}

void Playing::init(){
    t = new Text(std::to_string(gb::getScore()), vector2(gb::getWidth()/2, 50));
}