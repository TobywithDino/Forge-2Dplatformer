#include "headers/map.h"
#include "headers/game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>

vector<vector<int>> Map::levels;
vector<SDL_Surface*> Map::surfaces;
bool Map::showCollideBox;

int Map::init(){
    showCollideBox = false;

    // load png to surfaces
    if(loadSurface("res/maps/Forge-map-level1.png", surfaces) < 0) return -1;
    if(loadSurface("res/maps/Forge-map-level2.png", surfaces) < 0) return -1;

    // convert each surface to int arrays and store in levels
    for(SDL_Surface* surface : surfaces){
        SDL_PixelFormat *fmt;
        Uint32 temp, pixel;
        Uint8 red;

        fmt = surface->format;
        int totalPixels = surface->w * surface->h;
        vector<int> level;
        level.push_back(surface->w);
        level.push_back(surface->h);
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

int Map::loadSurface(const char* path, vector<SDL_Surface*>& surfaces){
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
    int mapWidth = levels[index][0];
    int mapHeight = levels[index][1];
    int pixelSizeW = Game::getWidth() / mapWidth;
    int pixelSizeH = Game::getHeight() / mapHeight; 
    for(int i=0;i<mapHeight;i++){
        for(int j=0;j<mapWidth;j++){
            if(i*mapWidth+j+2 > levels[index].size() - 1) continue;
            if(levels[index][i*mapWidth+j+2] == 0) continue;
            SDL_Rect dst;
            dst.w = pixelSizeW;
            dst.h = pixelSizeH;
            dst.x = j * pixelSizeW;
            dst.y = i * pixelSizeH;
            SDL_SetRenderDrawColor(Game::getRenderer(), 255, 255, 255, 255);
            SDL_RenderFillRect(Game::getRenderer(), &dst);

            // draw tiny collide boxes
            if(!showCollideBox) continue; // close and open the collide box display
            for(int m=0;m<pixelSizeH;m++){
                for(int n=0;n<pixelSizeW;n++){
                    if(m==0 || m==pixelSizeH-1 || n == 0 || n == pixelSizeW-1){
                        SDL_Rect dst;
                        dst.w = dst.h = 1;
                        dst.x = n + j * pixelSizeW;
                        dst.y = m + i * pixelSizeH;
                        SDL_SetRenderDrawColor(Game::getRenderer(), 50, 255, 50, 255);
                        SDL_RenderFillRect(Game::getRenderer(), &dst);
                    }
                }
            }
            
        }
    }

}