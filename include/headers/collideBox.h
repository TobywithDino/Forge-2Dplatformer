#pragma once
#include "SDL2/SDL.h"
#include "headers/gb.h"
#include "headers/vector2.h"
#include "headers/map.h"

enum CollideType{
    COL_default,
    COL_player,
    COL_none
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
    ~CollideBox() {delete box; delete pos;};
    CollideBox(CollideType type, vector2* pos);
    void handleEvent(SDL_Event e);
    void render();
    bool getIsCollidedHorizontal() {return isCollidedHorizontal;}
    bool getIsCollidedVertical() {return isCollidedVertical;}
    void setIsCollidedHorizontal(bool is) {isCollidedHorizontal = is;}
    void setIsCollidedVertical(bool is) {isCollidedVertical = is;}
    double getBoxLeft() {return pos->x + box->at(0);}
    double getBoxRight() {return pos->x + box->at(0) + box->at(2);}
    double getBoxTop() {return pos->y + box->at(1);}
    double getBoxDown() {return pos->y + box->at(1) + box->at(3);}

private:
    vector<int>* box;
    bool showCollideBox;
    bool isCollidedHorizontal;
    bool isCollidedVertical;
    vector2* pos;
};