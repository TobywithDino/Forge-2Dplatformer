#pragma once
#include "SDL2/SDL.h"
#include "headers/gb.h"
#include "headers/vector2.h"
#include "headers/map.h"

enum CollideType{
    COL_default,
    COL_player
};

class CollideBox{
public:
    static int init();
private:
    vector<int>* getCollideBox(CollideType type);
    static vector<SDL_Surface*> surfaces;
    static vector<vector<int>> collideBoxes;
    
public:
    CollideBox();
    CollideBox(CollideType type, vector2* pos);
    void handleEvent(SDL_Event e);
    void render();
private:
    vector<int>* box;
    bool showCollideBox;
    vector2* pos;
};