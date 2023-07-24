#include <stdio.h>
#include "headers/texture.h"
#include "headers/game.h"
#include "SDL2/SDL_image.h"

vector<SDL_Texture*> Texture::textures;

int Texture::init(){
    const char* path;
    SDL_Texture* tex;

    path = "res/Forge-player.png";
    tex = IMG_LoadTexture(Game::getRenderer(), path);
    if(tex == nullptr){
        printf("Error: failed to load texture\nTexture Error: '%s'\n", path);
        return -1;
    }
    textures.push_back(tex);
    return 0;
}

SDL_Texture* Texture::getTexture(TextureType type){
    switch (type)
    {
    case TEX_player:
        return textures[0];
        break;
    
    default:
        return nullptr;
        break;
    }
}