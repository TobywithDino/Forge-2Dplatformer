#include "headers/gameLoop/option.h"

void Option::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            optionButton->handleEvent(event);
        }
    }
}

void Option::update(){

}

void Option::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 30, 30, 30, 255);
    SDL_RenderClear(gb::getRenderer());
    optionButton->render();
    SDL_RenderPresent(gb::getRenderer());
}

void Option::init(){
    optionButton = new Button(vector2(gb::getWidth()/2, gb::getHeight()/2+200), TEX_button_menu_unpressed, TEX_button_menu_pressed, COLBOX_sprite_menuButton, vector2(64,64), GS_Menu);
}