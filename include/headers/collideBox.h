#pragma once
#include "headers/vector2.h"
#include "headers/map.h"

enum CollideBoxType{
    COLBOX_default,
    COLBOX_sprite_player,
    COLBOX_sprite_crawler,
    COLBOX_sprite_ploder,
    COLBOX_projectile_pistolBullet,
    COLBOX_projectile_revolverBullet,
    COLBOX_END
};

enum CollideType{
    COL_sprite,
    COL_player,
    COL_enemy,
    COL_level,
    COL_projectile
};
    

class CollideBox{

// static part
public:
    static int init();
    static vector<vector<int>>* getLevelCollideBox(LevelType levelType);
private:
    static int initCollideBoxes();
    static int initLevelCollideBoxes();
    static void loadPixelFromSurface(vector<SDL_Surface*> surfaces, vector<vector<int>>& boxes, vector2 scale = vector2(0,0));
    template<typename type>
    static void loadPixelFromSurface(int length, SDL_Surface** surfaces, vector<vector<int>>& boxes);
    vector<int>* getCollideBox(CollideBoxType boxType);
    static vector<vector<int>> collideBoxes;
    static vector<vector<vector<int>>> levelCollideBoxes;
    
// non-static part
public:
    CollideBox();
    CollideBox(CollideBoxType boxType, vector2* pos, CollideType type);
    CollideBox(vector<int>* box);
    static void handleEvent(SDL_Event e);
    void render();
    void setPos(vector2* pos) {this->entityPos = pos;}
    double getBoxLeft() {return entityPos->x + box->at(0);}
    double getBoxRight() {return entityPos->x + box->at(0) + box->at(2);}
    double getBoxTop() {return entityPos->y + box->at(1);}
    double getBoxDown() {return entityPos->y + box->at(1) + box->at(3);}
    vector2 getBoxOffset() {return vector2(box->at(0), box->at(1));}
    vector2 getBoxSize() {return vector2(box->at(2), box->at(3));}
    CollideType getCollideType() {return collideType;}
private:
    vector<int>* box = CollideBox::getCollideBox(COLBOX_default);
    static bool showCollideBox;
    vector2* entityPos = new vector2(0,0);
    CollideType collideType = COL_sprite;
};