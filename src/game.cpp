#include <stdio.h>
#include "headers/game.h"

int Game::SCREEN_WIDTH;
int Game::SCREEN_HEIGHT;
const char* Game::SCREEN_TITLE;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;
bool Game::running;

Game::Game(int w, int h, const char* t, bool r){
    setWidth(w);
    setHeight(h);
    setTitle(t);
    setRunning(r);
}

int Game::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    while(running){
        handleEvent();
        update();
        render();
    }

    return 0;
}

void Game::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                setRunning(false);
                break;

            default:
                break;
        }
    }
}

void Game::update(){

}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}