#include "headers/gameLoop/menu.h"

void Menu::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.scancode == SDL_SCANCODE_Z){
                    gb::setGameState(GS_Playing);
                }
            }
        }
    }
}

void Menu::update(){

}

void Menu::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 200, 200, 200, 255);
    SDL_RenderClear(gb::getRenderer());
    
    SDL_RenderPresent(gb::getRenderer());
}