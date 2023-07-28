#pragma once
#include "headers/texture.h"

class Map{
public:
    static int init();
    static void render(int index);
    static int loadSurface(const char* path, vector<SDL_Surface*>& surfaces);
private:
    static vector<vector<int>> levels;
    static vector<SDL_Surface*> surfaces;
};