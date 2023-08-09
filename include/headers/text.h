#pragma once
#include "headers/gb.h"

class Text{
// static part
public:
    static int init();
private:
    static TTF_Font* font;

// non-static part
public:
    Text();
    Text(string word, vector2 pos);
    Text(string word, vector2 pos, double sizeMultiplier, SDL_Color color = {255,255,255,255});
    void update(string word);
    void render();
private:
    string word = "t";
    vector2 pos = vector2(0,0);
    double sizeMultiplier = 1;
    SDL_Color color = {255,255,255,255};
};