#include "headers/collideBox.h"
#include <stdio.h>
vector<SDL_Surface*> CollideBox::surfaces;
vector<vector<int>> CollideBox::collideBoxes;
int CollideBox::init(){
    if(Map::loadSurface("res/collideBox/Forge-collideBox-default.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/Forge-collideBox-player.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/Forge-collideBox-none.png", surfaces) < 0) return -1;

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
                    if(boxWidth == surface->w){
                        findingWidth = false;
                        findingHeight = true;
                    }
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
        offsetX *= gb::getScale();
        offsetY *= gb::getScale();
        boxWidth *= gb::getScale();
        boxHeight *= gb::getScale();
        collideBox.push_back(offsetX); // at(0)
        collideBox.push_back(offsetY); // at(1)
        collideBox.push_back(boxWidth); // at(2)
        collideBox.push_back(boxHeight); // at(3)
        collideBoxes.push_back(collideBox);
    }
    return 0;
}

vector<int>* CollideBox::getCollideBox(CollideType type){
    switch (type)
    {
    case COL_default:
        return &collideBoxes[0];
        break;
    case COL_player:
        return &collideBoxes[1];
        break;
    case COL_none:
        return &collideBoxes[2];
        break;
    default:
        printf("Error: failed to get collideBox\nGetCollideBox Error: '%s'\n", type);
        return &collideBoxes[0];
        break;
    }
}

CollideBox::CollideBox(){
    box = CollideBox::getCollideBox(COL_none);
    showCollideBox = false;
    this->pos = new vector2(0,0);
}

CollideBox::CollideBox(CollideType type, vector2* pos){
    box = CollideBox::getCollideBox(type);
    showCollideBox = false;
    this->pos = pos;
}

void CollideBox::handleEvent(SDL_Event e){
    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_Q){
            if(showCollideBox) showCollideBox = false;
            else showCollideBox = true;
        }
    }
}

void CollideBox::render(){
    if(!showCollideBox) return;
    int offsetX = box->at(0);
    int offsetY = box->at(1);
    int boxWidth = box->at(2);
    int boxHeight = box->at(3);
    SDL_Rect dst;
    dst.x =  pos->x + offsetX;
    dst.y =  pos->y + offsetY;
    dst.w = boxWidth;
    dst.h = boxHeight;
    SDL_SetRenderDrawColor(gb::getRenderer(), 0, 255, 0, 255);
    SDL_RenderDrawRect(gb::getRenderer(), &dst);
}