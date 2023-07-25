#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/texture.h"
#include "headers/entity.h"
#include "headers/movableEntity.h"
#include "headers/player.h"
#include "headers/map.h"
#include "headers/collider.h"

#include <vector>
using namespace std;

class Game{
public:
    Game();
    int init();

    static int getWidth() {return SCREEN_WIDTH;}
    static int getHeight() {return SCREEN_HEIGHT;}
    static const char* getTitle() {return SCREEN_TITLE;}
    static double getScale() {return SCREEN_SCALE;}
    static bool getRunning() {return running;}
    static SDL_Window* getWindow() {return window;}
    static SDL_Renderer* getRenderer() {return renderer;}
    static int getDelTicks() {return delTicks;}

    static void setWidth(int w) {SCREEN_WIDTH = w;}
    static void setHeight(int h) {SCREEN_HEIGHT = h;}
    static void setTitle(const char* t) {SCREEN_TITLE = t;}
    static void setScale(double s) {SCREEN_SCALE = s;}
    static void setRunning(bool r) {running = r;}
    static void setFPS(int f) {FPS = f;}
    static void setDelTicks(int d) {delTicks = d;}
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
    static int delTicks;

    int lastTick;

    vector<MovableEntity*> entities;
    MovableEntity* player;
};