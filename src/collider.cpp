#include "headers/collider.h"
#include <stdio.h>

vector<SDL_Surface*> Collider::surfaces;
vector<vector<int>> Collider::collideBoxes;

int Collider::init(){
    if(Map::loadSurface("res/collideBox/Forge-collideBox-player.png", surfaces) < 0) return -1;

    // record the offsetX, offsetY, boxWidth, boxHeight of each surface's green box 
    for(SDL_Surface* surface : surfaces){
        SDL_PixelFormat *fmt;
        Uint32 temp, pixel;
        Uint8 green;

        fmt = surface->format;
        int totalPixels = surface->w * surface->h;
        vector<int> collideBox;
        bool foundTopLeftGreen = false;
        bool findingWidth = false;
        bool findingHeight = false;
        int offsetX = 0;
        int offsetY = 0;
        int boxWidth = 0;
        int boxHeight = 0;

        for(int i=0;i<totalPixels;i++){
            SDL_LockSurface(surface);
            pixel = *(((Uint32*)surface->pixels) + i);
            SDL_UnlockSurface(surface);

            // Get Green component
            temp = pixel & fmt->Gmask;  // Isolate red component
            temp = temp >> fmt->Gshift; // Shift it down to 8-bit 
            temp = temp << fmt->Gloss;  // Expand to a full 8-bit number
            green = (Uint8)temp;
            if(green == 255) {
                if(!foundTopLeftGreen){
                    foundTopLeftGreen = true;
                    findingWidth = true;
                    offsetX = i % surface->w;
                    offsetY = i / surface->w;
                }
                if(findingWidth){
                    boxWidth++;
                }
                if(findingHeight){
                    boxHeight++;
                    i+=surface->w-1;
                }
            }else if(findingWidth){
                findingWidth = false;
                findingHeight = true;
                boxHeight++;
                i+=surface->w-2;
            }else if(findingHeight){
                findingHeight = false;
                break;
            }
        }
        collideBox.push_back(offsetX);
        collideBox.push_back(offsetY);
        collideBox.push_back(boxWidth);
        collideBox.push_back(boxHeight);
        collideBoxes.push_back(collideBox);
    }

    return 0;
}

vector<int>* Collider::getCollideBox(ColliderType type){
    switch (type)
    {
    case COL_player:
        return &collideBoxes[0];
        break;
    
    default:
        printf("Error: failed to get collideBox\nGetCollideBox Error: '%s'\n", type);
        return nullptr;
        break;
    }
}