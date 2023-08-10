#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"
#include "headers/gameState.h"
#include "headers/vector2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

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
    static Uint64 getFrameTicks() {return frameTicks;}
    static Uint64 getLastTicks() {return lastTicks;}
    static GameState getGameState() {return state;}
    static int getScore() {return score;}

    static void setWidth(int w) {SCREEN_WIDTH = w;}
    static void setHeight(int h) {SCREEN_HEIGHT = h;}
    static void setTitle(const char* t) {SCREEN_TITLE = t;}
    static void setScale(double s) {SCREEN_SCALE = s;}
    static void setRunning(bool r) {running = r;}
    static void setWindow(SDL_Window* window) {gb::window = window;}
    static void setRenderer(SDL_Renderer* renderer) {gb::renderer = renderer;}
    static void setFPS(int f) {FPS = f;}
    static void setFrameTicks(Uint64 d) {frameTicks = d;}
    static void setLastTicks(Uint64 l) {lastTicks = l;}
    static void setGameState(GameState s) {state = s;}
    static void setScore(int s) {score = s;}

    static const int maxEnemyEntities = 50;
    static const int maxLevelEntities = 30;
    static const int maxProjtEntities = 30;
    static const int maxEntities = maxEnemyEntities + maxLevelEntities + maxProjtEntities + 2;
private:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static const char* SCREEN_TITLE;
    static double SCREEN_SCALE;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool running;
    static int FPS;
    static Uint64 frameTicks;
    static Uint64 lastTicks;
    static GameState state;
    static int score;
};