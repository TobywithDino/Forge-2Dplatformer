#pragma once
#include "SDL2/SDL.h"

class gb{
public:
    static int getWidth() {return SCREEN_WIDTH;}
    static int getHeight() {return SCREEN_HEIGHT;}
    static const char* getTitle() {return SCREEN_TITLE;}
    static double getScale() {return SCREEN_SCALE;}
    static bool getRunning() {return running;}
    static SDL_Window* getWindow() {return window;}
    static SDL_Renderer* getRenderer() {return renderer;}
    static int getFPS() {return FPS;}
    static int getDelTicks() {return delTicks;}
    static int getLastTicks() {return lastTicks;}

    static void setWidth(int w) {SCREEN_WIDTH = w;}
    static void setHeight(int h) {SCREEN_HEIGHT = h;}
    static void setTitle(const char* t) {SCREEN_TITLE = t;}
    static void setScale(double s) {SCREEN_SCALE = s;}
    static void setRunning(bool r) {running = r;}
    static void setWindow(SDL_Window* window) {gb::window = window;}
    static void setRenderer(SDL_Renderer* renderer) {gb::renderer = renderer;}
    static void setFPS(int f) {FPS = f;}
    static void setDelTicks(int d) {delTicks = d;}
    static void setLastTicks(int d) {lastTicks = d;}
private:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static const char* SCREEN_TITLE;
    static double SCREEN_SCALE;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool running;
    static int FPS;
    static int delTicks;
    static int lastTicks;
};