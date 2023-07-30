#include "headers/texture.h"

vector<SDL_Texture*> Texture::spriteTextures;
vector<SDL_Texture*> Texture::levelTextures;

int Texture::init(){
    if(loadTexture("res/sprites/Forge-sprite-testBlock.png", spriteTextures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-player.png", spriteTextures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-crawler.png", spriteTextures) < 0) return -1;


    if(loadTexture("res/sprites/Forge-sprite-level1.png", levelTextures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-level2.png", levelTextures) < 0) return -1;
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
    case TEX_sprite_crawler:
        return spriteTextures[2];
        break;
    case TEX_level_1:
        return levelTextures[0];
        break;
    case TEX_level_2:
        return levelTextures[1];
        break;
    default:
        printf("Error: failed to get texture\nGetTexture Error: '%s'\n", type);
        return nullptr;
        break;
    }
}

int Texture::loadTexture(const char* path, vector<SDL_Texture*>& textures){
    SDL_Texture* tex;
    tex = IMG_LoadTexture(gb::getRenderer(), path);
    if(tex == nullptr){
        printf("Error: failed to load texture\nTexture Error: '%s'\n", path);
        return -1;
    }
    textures.push_back(tex);
    return 0;
}