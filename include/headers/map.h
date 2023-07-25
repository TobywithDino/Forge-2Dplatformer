#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/gb.h"
#include <vector>
using namespace std;
class Map{
public:
    static int init();
    static void renderLevel(int index);
    static bool getShowCollideBox() {return showCollideBox;}
    static void setShowCollideBox(bool show) {showCollideBox = show;}
    static int loadSurface(const char* path, vector<SDL_Surface*>& surfaces);
private:
    static vector<vector<int>> levels;
    static vector<SDL_Surface*> surfaces;
    static bool showCollideBox;
};