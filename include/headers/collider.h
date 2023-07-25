#pragma once
#include "SDL2/SDL.h"
#include "headers/map.h"
#include <vector>
using namespace std;


enum ColliderType{
    COL_default,
    COL_player
};

class Collider{
public:
    static int init();
    static vector<int>* getCollideBox(ColliderType type);
private:
    static vector<SDL_Surface*> surfaces;
    static vector<vector<int>> collideBoxes;
};