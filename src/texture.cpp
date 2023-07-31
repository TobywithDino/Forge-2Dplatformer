#include "headers/texture.h"

vector<SDL_Texture*> Texture::spriteTextures;
vector<SDL_Texture*> Texture::levelTextures;
SDL_Texture* Texture::textures[TEX_END];

int Texture::init(){
    if(loadTexture("res/sprites/Forge-sprite-testBlock.png", TEX_sprite_testBlock) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-player.png", TEX_sprite_player) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-crawler.png", TEX_sprite_crawler) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-crawler_evolved.png", TEX_sprite_crawler_evolved) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-ploder.png", TEX_sprite_ploder) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-ploder_evolved.png", TEX_sprite_ploder_evolved) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-level1.png", TEX_sprite_level1) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-level2.png", TEX_sprite_level2) < 0) return -1;
    return 0;
}

SDL_Texture* Texture::getTexture(TextureType type){
    SDL_Texture* tex;
    tex = textures[type];
    if(tex == nullptr) printf("Error: failed to get texture\nGetTexture Error: '%d'\n", type);
    return tex;
}

int Texture::loadTexture(const char* path, TextureType type){
    SDL_Texture* tex;
    tex = IMG_LoadTexture(gb::getRenderer(), path);
    if(tex == nullptr){
        printf("Error: failed to load texture\nTexture Error: '%s'\n", path);
        return -1;
    }
    textures[type] = tex;
    return 0;
}