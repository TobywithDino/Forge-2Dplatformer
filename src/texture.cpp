#include "headers/texture.h"
#include <stdio.h>

vector<SDL_Texture*> Texture::spriteTextures;

int Texture::init(){
    if(loadTexture("res/sprites/Forge-sprite-testBlock.png") < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-player.png") < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-none.png") < 0) return -1;
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
    case TEX_sprite_none:
        return spriteTextures[2];
        break;
    default:
        printf("Error: failed to get texture\nGetTexture Error: '%s'\n", type);
        return nullptr;
        break;
    }
}

int Texture::loadTexture(const char* path){
    SDL_Texture* tex;
    tex = IMG_LoadTexture(gb::getRenderer(), path);
    if(tex == nullptr){
        printf("Error: failed to load texture\nTexture Error: '%s'\n", path);
        return -1;
    }
    spriteTextures.push_back(tex);
    return 0;
}