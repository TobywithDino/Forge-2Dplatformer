#include "headers/map.h"
#include "headers/game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>

vector<vector<int>> Map::levels;
vector<SDL_Surface*> Map::surfaces;
int Map::MAP_WIDTH;
int Map::MAP_HEIGHT;
int Map::PIXEL_SIZE;
bool Map::showCollideBox;

int Map::init(){
    // set WIDTH, HEIGHT and PixelSize
    MAP_WIDTH = 30; // Big pixels
    MAP_HEIGHT = 22;
    PIXEL_SIZE = Game::getWidth() / MAP_WIDTH;
    showCollideBox = false;

    // load png to surfaces
    if(loadSurface("res/maps/Forge-level1.png") < 0) return -1;
    if(loadSurface("res/maps/Forge-level2.png") < 0) return -1;

    // convert each surface to int arrays and store in levels
    for(SDL_Surface* surface : surfaces){
        SDL_PixelFormat *fmt;
        Uint32 temp, pixel;
        Uint8 red;

        fmt = surface->format;
        int totalPixels = MAP_WIDTH * MAP_HEIGHT;
        vector<int> level;
        for(int i=0;i<totalPixels;i++){
            SDL_LockSurface(surface);
            pixel = *(((Uint32*)surface->pixels) + i);
            SDL_UnlockSurface(surface);

            // Get Red component
            temp = pixel & fmt->Rmask;  // Isolate red component
            temp = temp >> fmt->Rshift; // Shift it down to 8-bit 
            temp = temp << fmt->Rloss;  // Expand to a full 8-bit number
            red = (Uint8)temp;
            if(red == 255) level.push_back(1);
            else level.push_back(0);
        }
        levels.push_back(level);
    }

    return 0;
}

int Map::loadSurface(const char* path){
    SDL_Surface* surface;
    surface = IMG_Load(path);
    if(surface == nullptr){
        printf("Error: failed to load surface\nMap::init() Error: '%s'\n", path);
        return -1;
    }
    surfaces.push_back(surface);
    return 0;
}

void Map::renderLevel(int index){
    for(int i=0;i<MAP_HEIGHT;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            if(levels[index][i*MAP_WIDTH+j] == 0) continue;
            SDL_Rect dst;
            dst.w = dst.h = PIXEL_SIZE;
            dst.x = j * PIXEL_SIZE;
            dst.y = i * PIXEL_SIZE;
            SDL_SetRenderDrawColor(Game::getRenderer(), 255, 255, 255, 255);
            SDL_RenderFillRect(Game::getRenderer(), &dst);

            // draw tiny collide boxes
            if(!showCollideBox) continue; // close and open the collide box display
            for(int m=0;m<PIXEL_SIZE;m++){
                for(int n=0;n<PIXEL_SIZE;n++){
                    if(m==0 || m==PIXEL_SIZE-1 || n == 0 || n == PIXEL_SIZE-1){
                        SDL_Rect dst;
                        dst.w = dst.h = 1;
                        dst.x = n + j * PIXEL_SIZE;
                        dst.y = m + i * PIXEL_SIZE;
                        SDL_SetRenderDrawColor(Game::getRenderer(), 50, 255, 50, 255);
                        SDL_RenderFillRect(Game::getRenderer(), &dst);
                    }
                }
            }
            
        }
    }

}