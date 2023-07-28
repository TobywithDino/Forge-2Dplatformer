#pragma once
#include "headers/gb.h"

enum TextureType{
    TEX_sprite_testBlock,
    TEX_sprite_player,
};

class Texture{
public:
    static int init();
    static SDL_Texture* getTexture(TextureType type);
private:
    static vector<SDL_Texture*> spriteTextures;
    static int loadTexture(const char* path);
};