#include <stdio.h>
#include "headers/game.h"

int Game::SCREEN_WIDTH;
int Game::SCREEN_HEIGHT;
const char* Game::SCREEN_TITLE;
double Game::SCREEN_SCALE;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;
bool Game::running;
int Game::FPS;
int Game::delTicks;

Game::Game(int width, int height, const char* title, double scale, bool running, int fps){
    setWidth(width);
    setHeight(height);
    setTitle(title);
    setScale(scale);
    setRunning(running);
    setFPS(fps);
    setDelTicks(0);
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

    if(Texture::init() < 0){
        return 1;
    }

    MovableEntity* e;
    e = new MovableEntity(vector2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2), TEX_testBlock);
    entities.push_back(e);
    player = new Player();
    
    lastTick = SDL_GetTicks64();
    while(running){
        handleEvent();
        if(SDL_GetTicks64() - lastTick > 1000/FPS){
            setDelTicks(SDL_GetTicks64() - lastTick);
            lastTick = SDL_GetTicks64();
            update();
            render();
        }
    }

    return 0;
}

void Game::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) setRunning(false);
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
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);
    player->render();
    for(Entity* entity : entities) entity->render();
    SDL_RenderPresent(renderer);
}