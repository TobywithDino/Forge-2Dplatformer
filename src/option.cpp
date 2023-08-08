#include "headers/gameLoop/option.h"

void Option::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            
        }
    }
}

void Option::update(){

}

void Option::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 30, 30, 30, 255);
    SDL_RenderClear(gb::getRenderer());

    SDL_RenderPresent(gb::getRenderer());
}

void Option::init(){

}