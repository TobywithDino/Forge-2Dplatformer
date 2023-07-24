#pragma once
#include "SDL2/SDL.h"
#include <vector>
using namespace std;

class Map{
public:
    static int init();
    static void renderLevel(int index);
private:
    static vector<vector<int>> levels;
    static vector<SDL_Surface*> surfaces;
    static int MAP_WIDTH; // 1 Big pixel per PIXEL_SIZE pixels
    static int MAP_HEIGHT;
    static int PIXEL_SIZE;

    static int loadSurface(const char* path);
};