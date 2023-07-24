#include <stdio.h>
#include "headers/texture.h"
#include "headers/game.h"
#include "SDL2/SDL_image.h"

vector<SDL_Texture*> Texture::spriteTextures;

int Texture::init(){
    if(loadTexture("res/sprites/Forge-testBlock.png") < 0) return -1;
    if(loadTexture("res/sprites/Forge-player.png") < 0) return -1;

    return 0;
}

SDL_Texture* Texture::getTexture(TextureType type){
    switch (type)
    {
    case TEX_sprite_testBlock:
        return spriteTextures[0];
        break;
    case TEX_sprite_player:
        return spriteTextures[1];
        break;
    default:
        printf("Error: failed to get texture\nGetTexture Error: '%s'\n", type);
        return nullptr;
        break;
    }
}

int Texture::loadTexture(const char* path){
    SDL_Texture* tex;
    tex = IMG_LoadTexture(Game::getRenderer(), path);
    if(tex == nullptr){
        printf("Error: failed to load texture\nTexture Error: '%s'\n", path);
        return -1;
    }
    spriteTextures.push_back(tex);
    return 0;
}