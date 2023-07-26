#pragma once
#include "SDL2/SDL_image.h"
#include "headers/gb.h"
#include <vector>
using namespace std;

enum TextureType{
    TEX_sprite_testBlock,
    TEX_sprite_player,
    TEX_sprite_none
};

class Texture{
public:
    static int init();
    static SDL_Texture* getTexture(TextureType type);
private:
    static vector<SDL_Texture*> spriteTextures;
    static int loadTexture(const char* path);
};