#include "headers/gameLoop/option.h"

void Option::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            for(int i=0;i<3;i++){
                optionButtons[i]->handleEvent(event);
            }
        }
    }
}

void Option::update(){
     if(optionButtons[1]->isPressing()){
        optionButtons[1]->rstPressing();
        musPercent -= 5;
        if(musPercent <= 0) musPercent = 100;
        Sound::setMusVolumn(musPercent);
        optionTexts[0]->update(to_string(musPercent)+"%");
    }
    if(optionButtons[2]->isPressing()){
        optionButtons[2]->rstPressing();
        sfxPercent -= 5;
        if(sfxPercent <= 0) sfxPercent = 100;
        Sound::setSFXVolumn(sfxPercent);
        optionTexts[1]->update(to_string(sfxPercent)+"%");
    }
}

void Option::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 30, 30, 30, 255);
    SDL_RenderClear(gb::getRenderer());
    for(int i=0;i<3;i++){
        optionButtons[i]->render();
    }

    for(int i=0;i<2;i++){
        optionTexts[i]->render();
    }
    SDL_RenderPresent(gb::getRenderer());
}

void Option::init(){
    Button* menuButton = new Button(vector2(gb::getWidth()/2, gb::getHeight()/2+200), TEX_button_menu_unpressed, TEX_button_menu_pressed, COLBOX_sprite_menuButton, vector2(64,64), GS_Menu);
    Button* musicButton = new Button(vector2(gb::getWidth()/2-100, gb::getHeight()/2-100), TEX_button_music_unpressed,TEX_button_music_pressed,COLBOX_sprite_musicButton,vector2(64,64));
    Button* sfxButton = new Button(vector2(gb::getWidth()/2-100, gb::getHeight()/2), TEX_button_sfx_unpressed, TEX_button_sfx_pressed, COLBOX_sprite_musicButton, vector2(64,64));
    optionButtons[0] = menuButton;
    optionButtons[1] = musicButton;
    optionButtons[2] = sfxButton;

    Text* musText = new Text(to_string(musPercent)+"%",vector2(gb::getWidth()/2+50, gb::getHeight()/2-100));
    Text* sfxText = new Text(to_string(sfxPercent)+"%",vector2(gb::getWidth()/2+50, gb::getHeight()/2));
    optionTexts[0] = musText;
    optionTexts[1] = sfxText;
}