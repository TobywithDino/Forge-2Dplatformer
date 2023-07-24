#pragma once
#include "SDL2/SDL.h"

class Game{
public:
    Game(int w, int h, const char* t, bool r);
    int init();

    int getWidth() {return SCREEN_WIDTH;}
    int getHeight() {return SCREEN_HEIGHT;}
    const char* getTitle() {return SCREEN_TITLE;}
    bool getRunning() {return running;}
    SDL_Window* getWindow() {return window;}
    SDL_Renderer* getRenderer() {return renderer;}

    void setWidth(int w) {SCREEN_WIDTH = w;}
    void setHeight(int h) {SCREEN_HEIGHT = h;}
    void setTitle(const char* t) {SCREEN_TITLE = t;}
    void setRunning(bool r) {running = r;}
private:
    void handleEvent();
    void update();
    void render();

    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static const char* SCREEN_TITLE;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool running;
};