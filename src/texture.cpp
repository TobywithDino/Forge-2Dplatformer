#include <stdio.h>
#include "headers/texture.h"
#include "headers/game.h"
#include "SDL2/SDL_image.h"

vector<SDL_Texture*> Texture::textures;

int Texture::init(){
    const char* path;

    path = "res/Forge-testBlock.png";
    if(loadTexture(path) < 0) return -1;

    path = "res/Forge-player.png";
    if(loadTexture(path) < 0) return -1;

    return 0;
}

SDL_Texture* Texture::getTexture(TextureType type){
    switch (type)
    {
    case TEX_testBlock:
        return textures[0];
        break;
    case TEX_player:
        return textures[1];
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
    textures.push_back(tex);
    return 0;
}