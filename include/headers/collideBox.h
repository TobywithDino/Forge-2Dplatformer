#pragma once
#include "SDL2/SDL.h"
#include "headers/gb.h"
#include "headers/vector2.h"
#include "headers/map.h"

enum CollideType{
    COL_default,
    COL_player,
};
enum LevelCollideType{
    COL_level_1,
    COL_level_2
};
    

class CollideBox{

// static part
public:
    static int init();
    static vector<vector<int>>* getLevelCollideBox(LevelCollideType type);
private:
    static int initCollideBoxes();
    static int initLevelCollideBoxes();
    static void loadPixelFromSurface(vector<SDL_Surface*> surfaces, vector<vector<int>>& boxes, vector2 scale = vector2(1,1));
    vector<int>* getCollideBox(CollideType type);
    static vector<vector<int>> collideBoxes;
    static vector<vector<int>> levelCollideBoxes_1;
    static vector<vector<int>> levelCollideBoxes_2;
    
// non-static part
public:
    CollideBox();
    CollideBox(CollideType type, vector2* pos);
    CollideBox(vector<int>* box);
    void handleEvent(SDL_Event e);
    void render();
    double getBoxLeft() {return pos->x + box->at(0);}
    double getBoxRight() {return pos->x + box->at(0) + box->at(2);}
    double getBoxTop() {return pos->y + box->at(1);}
    double getBoxDown() {return pos->y + box->at(1) + box->at(3);}
    vector2 getBoxOffset() {return vector2(box->at(0), box->at(1));}
    vector2 getBoxSize() {return vector2(box->at(2), box->at(3));}

private:
    vector<int>* box;
    bool showCollideBox;
    vector2* pos;
};