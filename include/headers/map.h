#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/gb.h"
#include <vector>
using namespace std;
class Map{
public:
    static int init();
    static void render(int index);
    static int loadSurface(const char* path, vector<SDL_Surface*>& surfaces);
private:
    static vector<vector<int>> levels;
    static vector<SDL_Surface*> surfaces;
};