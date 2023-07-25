#pragma once
#include "SDL2/SDL.h"
#include "headers/gb.h"
#include "headers/collider.h"
#include "headers/vector2.h"
#include "headers/map.h"
class CollideBox{
public:
    CollideBox();
    CollideBox(ColliderType type, vector2* pos);
    void handleEvent(SDL_Event e);
    void render();
    bool checkHorizontal();
    bool checkVertical();
private:
    vector<int>* box;
    bool showCollideBox;
    vector2* pos;
};