#include "headers/collideBox.h"
#include <stdio.h>

vector<vector<int>> CollideBox::collideBoxes;
vector<vector<int>> CollideBox::levelCollideBoxes_1;
vector<vector<int>> CollideBox::levelCollideBoxes_2;
/*
        static part
*/

int CollideBox::init(){
    if(initCollideBoxes() < 0) return -1;
    if(initLevelCollideBoxes() < 0) return -1;
    return 0;
}

int CollideBox::initCollideBoxes(){
    vector<SDL_Surface*> surfaces;
    if(Map::loadSurface("res/collideBox/sprites/Forge-collideBox-default.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/sprites/Forge-collideBox-player.png", surfaces) < 0) return -1;
    loadPixelFromSurface(surfaces, collideBoxes);
    return 0;
}

int CollideBox::initLevelCollideBoxes(){
    vector<SDL_Surface*> surfaces;

    if(Map::loadSurface("res/collideBox/level1/Layer 1.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 2.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 3.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 4.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 5.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 6.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 7.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 8.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 9.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 10.png", surfaces) < 0) return -1;
    loadPixelFromSurface(surfaces, levelCollideBoxes_1, vector2(gb::getWidth() / gb::getScale() / surfaces[0]->w,gb::getHeight() / gb::getScale() / surfaces[0]->h));
    surfaces.clear();
    
    if(Map::loadSurface("res/collideBox/level2/Layer 1.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 2.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 3.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 4.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 5.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 6.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 7.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 8.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 9.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 10.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 11.png", surfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 12.png", surfaces) < 0) return -1;
    loadPixelFromSurface(surfaces, levelCollideBoxes_2, vector2(gb::getWidth() / gb::getScale() / surfaces[0]->w,gb::getHeight() / gb::getScale() / surfaces[0]->h));
    surfaces.clear();
    
    return 0;
}

void CollideBox::loadPixelFromSurface(vector<SDL_Surface*> surfaces, vector<vector<int>>& boxes, vector2 scale){
    // record the offsetX, offsetY, boxWidth, boxHeight of each surface's green box 
    for(SDL_Surface* surface : surfaces){
        SDL_PixelFormat *fmt;
        Uint32 temp, pixel;
        Uint8 green;

        fmt = surface->format;
        int totalPixels = surface->w * surface->h;
        vector<int> box;
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
        offsetX *= gb::getScale() * scale.x;
        offsetY *= gb::getScale() * scale.y;
        boxWidth *= gb::getScale() * scale.x;
        boxHeight *= gb::getScale()* scale.y;
        box.push_back(offsetX); // at(0)
        box.push_back(offsetY); // at(1)
        box.push_back(boxWidth); // at(2)
        box.push_back(boxHeight); // at(3)
        boxes.push_back(box);
    }
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
    default:
        printf("Error: failed to get collideBox\nGetCollideBox Error: '%s'\n", type);
        return &collideBoxes[0];
        break;
    }
}

vector<vector<int>>* CollideBox::getLevelCollideBox(LevelCollideType type){
    switch (type)
    {
    case COL_level_1:
        return &levelCollideBoxes_1;
        break;
    case COL_level_2:
        return &levelCollideBoxes_2;
        break;
    default:
        printf("Error: failed to get levelCollideBox\nGetLevelCollideLBox Error: '%s'\n", type);
        return &levelCollideBoxes_1;
        break;
    }
}

/*
        non-static part
*/

CollideBox::CollideBox(){
}

CollideBox::CollideBox(CollideType type, vector2* pos){
    box = CollideBox::getCollideBox(type);
    this->entityPos = pos;
}

// for level box
CollideBox::CollideBox(vector<int>* box){
    this->box = box;
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
    dst.x =  entityPos->x + offsetX;
    dst.y =  entityPos->y + offsetY;
    dst.w = boxWidth;
    dst.h = boxHeight;
    SDL_SetRenderDrawColor(gb::getRenderer(), 0, 255, 0, 255);
    SDL_RenderDrawRect(gb::getRenderer(), &dst);
}