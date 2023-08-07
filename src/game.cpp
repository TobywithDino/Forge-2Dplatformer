#include "headers/game.h"

Game::Game(){
    gb::setWidth(1280);
    gb::setHeight(720);
    gb::setTitle("Forge");
    gb::setScale(2);
    gb::setRunning(true);
    gb::setFPS(120);
    gb::setFrameTicks(0);
    gb::setGameState(GS_Menu);
    Map::setLevelType(LEV_1);
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
    
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Error: Mix failed to initialize\nMix Error: '%s'\n", Mix_GetError());
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
    
    if(Texture::init() < 0) return 1;
    if(Anim::init() < 0) return 1;
    if(Map::init() < 0) return 1;
    if(CollideBox::init() < 0) return 1;
    if(AllSprite::init() < 0) return 1;
    if(Sound::init() < 0) return 1;
    
    menu.init();
    
    return 0;
}

void Game::start(){
    gb::setLastTicks(SDL_GetTicks64());
    while(gb::getRunning()){
        GameState state = gb::getGameState();
        switch (state)
        {
        case GS_Menu:
            menu.handleEvent();
            if(SDL_GetTicks64() - gb::getLastTicks() > 1000/gb::getFPS()){
                gb::setFrameTicks(SDL_GetTicks64() - gb::getLastTicks());
                gb::setLastTicks(SDL_GetTicks64());
                menu.update();
                menu.render();
            }
            break;
        case GS_Playing:
            playing.handleEvent();
            if(SDL_GetTicks64() - gb::getLastTicks() > 1000/gb::getFPS()){
                gb::setFrameTicks(SDL_GetTicks64() - gb::getLastTicks());
                gb::setLastTicks(SDL_GetTicks64());
                playing.update();
                playing.render();
            }
            break;
        case GS_GameOver:
            gameOver.handleEvent();
            if(SDL_GetTicks64() - gb::getLastTicks() > 1000/gb::getFPS()){
                gb::setFrameTicks(SDL_GetTicks64() - gb::getLastTicks());
                gb::setLastTicks(SDL_GetTicks64());
                gameOver.update();
                gameOver.render();
            }
            break;
        default:
            break;
        }
    }
}