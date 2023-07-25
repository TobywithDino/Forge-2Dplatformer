#include <stdio.h>
#include "headers/game.h"

Game::Game(){
    gb::setWidth(960);
    gb::setHeight(704);
    gb::setTitle("Forge");
    gb::setScale(1.5);
    gb::setRunning(true);
    gb::setFPS(60);
    gb::setDelTicks(0);
}

int Game::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
        printf("Error: IMG failed to initialize\nIMG Error: '%s'\n", IMG_GetError());
        return 1;
    }

    gb::setWindow(SDL_CreateWindow(gb::getTitle(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gb::getWidth(), gb::getHeight(), 0));
    if(!gb::getWindow()){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    gb::setRenderer(SDL_CreateRenderer(gb::getWindow(), -1, SDL_RENDERER_ACCELERATED));
    if(!gb::getRenderer()){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    if(Texture::init() < 0){
        return 1;
    }

    if(Map::init() < 0){
        return 1;
    }

    if(Collider::init() < 0){
        return 1;
    }

    MovableEntity* e;
    e = new MovableEntity(vector2(gb::getWidth()/2, gb::getWidth()/2), TEX_sprite_testBlock, COL_default);
    entities.push_back(e);
    player = new Player(vector2(200, 200));
    
    gb::setLastTicks(SDL_GetTicks64());
    while(gb::getRunning()){
        handleEvent();
        if(SDL_GetTicks64() - gb::getLastTicks() > 1000/gb::getFPS()){
            gb::setDelTicks(SDL_GetTicks64() - gb::getLastTicks());
            gb::setLastTicks(SDL_GetTicks64());
            update();
            render();
        }
    }

    return 0;
}

void Game::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) gb::setRunning(false);
        else{
            player->handleEvent(event);
            for(MovableEntity* entity : entities) entity->handleEvent(event);
        }
    }
}

void Game::update(){
    player->update();
    for(MovableEntity* entity : entities) entity->update();
}

void Game::render(){
    SDL_SetRenderDrawColor(gb::getRenderer(), 20, 20, 20, 255);
    SDL_RenderClear(gb::getRenderer());
    Map::renderLevel(1);
    player->render();
    for(Entity* entity : entities) entity->render();
    SDL_RenderPresent(gb::getRenderer());
}