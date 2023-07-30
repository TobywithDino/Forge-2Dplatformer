#pragma once
#include "headers/gb.h"

enum TextureType{
    TEX_sprite_testBlock,
    TEX_sprite_player,
    TEX_sprite_crawler,
    TEX_sprite_crawler_evolved,
    TEX_sprite_ploder,
    TEX_sprite_ploder_evolved,
    
    TEX_level_1,
    TEX_level_2
};

class Texture{
public:
    static int init();
    static SDL_Texture* getTexture(TextureType type);
private:
    static vector<SDL_Texture*> spriteTextures;
    static vector<SDL_Texture*> levelTextures;
    static int loadTexture(const char* path, vector<SDL_Texture*>& textures);
};