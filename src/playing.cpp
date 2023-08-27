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
    int i = (int)Map::getLevelType();
    background[i]->render();
    AllSprite::render();
    t->render();
    SDL_RenderPresent(gb::getRenderer());
}

void Playing::init(){
    t = new Text(std::to_string(gb::getScore()), vector2(gb::getWidth()/2, 50));
    background[LEV_1] = new Entity(vector2(0,0),TEX_sprite_background_level1, COLBOX_END, COL_END,vector2(gb::getWidth()/gb::getScale(),gb::getHeight()/gb::getScale()));
    background[LEV_2] = new Entity(vector2(0,0),TEX_sprite_background_level2, COLBOX_END, COL_END,vector2(gb::getWidth()/gb::getScale(),gb::getHeight()/gb::getScale()));
    background[LEV_3] = new Entity(vector2(0,0),TEX_sprite_background_level3, COLBOX_END, COL_END,vector2(gb::getWidth()/gb::getScale(),gb::getHeight()/gb::getScale()));
}