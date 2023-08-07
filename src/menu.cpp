#include "headers/gameLoop/menu.h"

void Menu::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            for(int i=0;i<3;i++){
                menuButtons[i]->handleEvent(event);
            }
        }
    }
}

void Menu::update(){
    for(int i=0;i<3;i++){
        menuButtons[i]->update();
    }
}

void Menu::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 30, 30, 30, 255);
    SDL_RenderClear(gb::getRenderer());
    for(int i=0;i<3;i++){
        menuButtons[i]->render();
    }
    SDL_RenderPresent(gb::getRenderer());
}

void Menu::init(){
    Button* startButton = new Button(vector2(gb::getWidth()/2, gb::getHeight()/2), TEX_button_start_unpressed, TEX_button_start_pressed, COLBOX_sprite_menuButton, vector2(64,64), GS_Playing);
    Button* optionButton = new Button(vector2(gb::getWidth()/2, gb::getHeight()/2+100), TEX_button_option_unpressed, TEX_button_option_pressed, COLBOX_sprite_menuButton, vector2(64,64), GS_Menu);
    Button* quitButton = new Button(vector2(gb::getWidth()/2, gb::getHeight()/2+200), TEX_button_quit_unpressed, TEX_button_quit_pressed, COLBOX_sprite_menuButton, vector2(64,64), GS_Quit);
    menuButtons[0] = startButton;
    menuButtons[1] = optionButton;
    menuButtons[2] = quitButton;
}