#include "headers/gameLoop/gameOver.h"

void GameOver::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.scancode == SDL_SCANCODE_Z){
                    gb::setGameState(GS_Playing);
                }
            }
            gameOverButton->handleEvent(event);
        }
    }
}

void GameOver::update(){
    t->update("Score : " + to_string(gb::getScore()));
}

void GameOver::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 50, 50, 50, 255);
    SDL_RenderClear(gb::getRenderer());
    t->render();
    gameOverButton->render();
    SDL_RenderPresent(gb::getRenderer());
}

void GameOver::init(){
    t = new Text("Score", vector2(gb::getWidth()/2,gb::getHeight()/2-100));
    gameOverButton = new Button(vector2(gb::getWidth()/2,gb::getHeight()/2+100),TEX_button_menu_unpressed,TEX_button_menu_pressed,COLBOX_sprite_menuButton,vector2(64,64),GS_Menu);
}