#include "headers/gameLoop/selectLevel.h"

void SelectLevel::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            for(int i=0;i<4;i++){
                selectButtons[i]->handleEvent(event);
            }
        }
    }
}

void SelectLevel::update(){
    if(selectButtons[1]->isPressing()){
        selectButtons[1]->rstPressing();
        if(level > LEV_1){
            level = (LevelType)(level - 1);
            Map::setLevelType(level);
            TextureType tmp = TEX_sprite_map_level1;
            tmp = (TextureType)((int)tmp + (int)level);
            e->setTexture(tmp);
        }
    }else if(selectButtons[2]->isPressing()){
        selectButtons[2]->rstPressing();
        if(level < LEV_END-1){
            level = (LevelType)(level + 1);
            Map::setLevelType(level);
            TextureType tmp = TEX_sprite_map_level1;
            tmp = (TextureType)((int)tmp + (int)level);
            e->setTexture(tmp);
        }
    }
}

void SelectLevel::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 30, 30, 30, 255);
    SDL_RenderClear(gb::getRenderer());
    for(int i=0;i<4;i++){
        selectButtons[i]->render();
    }
    t->render();
    e->render();
    SDL_RenderPresent(gb::getRenderer());
}

void SelectLevel::init(){
    selectButtons[0] = new Button(vector2(gb::getWidth()/2, gb::getHeight()/2+200), TEX_button_menu_unpressed, TEX_button_menu_pressed, COLBOX_sprite_menuButton, vector2(64,64), GS_Menu);
    selectButtons[1] = new Button(vector2(gb::getWidth()/2-200, gb::getHeight()/2),TEX_button_selectLeft_unpressed,TEX_button_selectLeft_pressed, COLBOX_sprite_musicButton, vector2(64,64));
    selectButtons[2] = new Button(vector2(gb::getWidth()/2+200, gb::getHeight()/2),TEX_button_selectRight_unpressed,TEX_button_selectRight_pressed, COLBOX_sprite_musicButton, vector2(64,64));
    selectButtons[3] = new Button(vector2(gb::getWidth()/2, gb::getHeight()/2+120), TEX_button_play_unpressed, TEX_button_play_pressed, COLBOX_sprite_menuButton, vector2(64,64), GS_Playing);
    t = new Text("Choose Level", vector2(gb::getWidth()/2, gb::getHeight()/2-200));
    e = new StaticEntity(vector2(gb::getWidth()/2-32*gb::getScale(), gb::getHeight()/2-32*gb::getScale()), vector2(64,64));
    e->setTexture(TEX_sprite_map_level1);
}