#pragma once
#include "SDL2/SDL.h"
#include <vector>
using namespace std;

enum TextureType{
    TEX_testBlock,
    TEX_player
};

class Texture{
public:
    static int init();
    static SDL_Texture* getTexture(TextureType type);
private:
    static vector<SDL_Texture*> textures;
    static int loadTexture(const char* path);
};