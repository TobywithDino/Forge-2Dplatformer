#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "headers/gameState.h"
#include <stdio.h>
#include <vector>
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
    static int getFrameTicks() {return frameTicks;}
    static int getLastTicks() {return lastTicks;}
    static int getLevelIndex() {return levelIndex;}
    static GameState getGameState() {return state;}
    static const int maxEnemyEntities = 20;
    static const int maxLevelEntities = 20;
    static const int maxEntities = maxEnemyEntities + maxLevelEntities + 1;

    static void setWidth(int w) {SCREEN_WIDTH = w;}
    static void setHeight(int h) {SCREEN_HEIGHT = h;}
    static void setTitle(const char* t) {SCREEN_TITLE = t;}
    static void setScale(double s) {SCREEN_SCALE = s;}
    static void setRunning(bool r) {running = r;}
    static void setWindow(SDL_Window* window) {gb::window = window;}
    static void setRenderer(SDL_Renderer* renderer) {gb::renderer = renderer;}
    static void setFPS(int f) {FPS = f;}
    static void setFrameTicks(int d) {frameTicks = d;}
    static void setLastTicks(int l) {lastTicks = l;}
    static void setLevelIndex(int l) {levelIndex = l;}
    static void setGameState(GameState s) {state = s;}
private:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static const char* SCREEN_TITLE;
    static double SCREEN_SCALE;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static bool running;
    static int FPS;
    static int frameTicks;
    static int lastTicks;
    static int levelIndex;
    static GameState state;
};