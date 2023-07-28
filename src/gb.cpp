#include "headers/gb.h"

int gb::SCREEN_WIDTH;
int gb::SCREEN_HEIGHT;
const char* gb::SCREEN_TITLE;
double gb::SCREEN_SCALE;
SDL_Window* gb::window;
SDL_Renderer* gb::renderer;
bool gb::running;
int gb::FPS;
int gb::frameTicks;
int gb::lastTicks;
int gb::levelIndex;
GameState gb::state;
