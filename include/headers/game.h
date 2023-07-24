#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/texture.h"
#include "headers/entity.h"

#include <vector>
using namespace std;

class Game{
public:
    Game(int width, int height, const char* title, double scale, bool running, int fps);
    int init();

    static int getWidth() {return SCREEN_WIDTH;}
    static int getHeight() {return SCREEN_HEIGHT;}
    static const char* getTitle() {return SCREEN_TITLE;}
    static double getScale() {return SCREEN_SCALE;}
    static bool getRunning() {return running;}
    static SDL_Window* getWindow() {return window;}
    static SDL_Renderer* getRenderer() {return renderer;}

    static void setWidth(int w) {SCREEN_WIDTH = w;}
    static void setHeight(int h) {SCREEN_HEIGHT = h;}
    static void setTitle(const char* t) {SCREEN_TITLE = t;}
    static void setScale(double s) {SCREEN_SCALE = s;}
    static void setRunning(bool r) {running = r;}
    static void setFPS(int f) {FPS = f;}
private:
    void handleEvent();
    void update();
    void render();

    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static const char* SCREEN_TITLE;
    static double SCREEN_SCALE;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool running;
    static int FPS;

    int lastTick;

    vector<Entity*> entities;
};