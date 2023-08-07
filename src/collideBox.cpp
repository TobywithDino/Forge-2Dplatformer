#include "headers/collideBox.h"

vector<vector<int>> CollideBox::collideBoxes(COLBOX_END);
vector<vector<vector<int>>> CollideBox::levelCollideBoxes(LEV_END);
bool CollideBox::showCollideBox = false;
/*
        static part
*/

int CollideBox::init(){
    if(initCollideBoxes() < 0) return -1;
    if(initLevelCollideBoxes() < 0) return -1;
    return 0;
}

int CollideBox::initCollideBoxes(){
    SDL_Surface* boxSurfaces[COLBOX_END];
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/sprites/Forge-collideBox-default.png", COLBOX_default, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/sprites/Forge-collideBox-player.png", COLBOX_sprite_player, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/sprites/Forge-collideBox-crawler.png", COLBOX_sprite_crawler, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/sprites/Forge-collideBox-ploder.png", COLBOX_sprite_ploder, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/sprites/Forge-collideBox-weaponBox.png", COLBOX_sprite_weaponBox, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/sprites/Forge-collideBox-button-start.png", COLBOX_sprite_menuButton, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/projectile/Forge-collideBox-pistolBullet.png", COLBOX_projectile_pistolBullet, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/projectile/Forge-collideBox-revolverBullet.png", COLBOX_projectile_revolverBullet, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/projectile/Forge-collideBox-dualgunBullet.png", COLBOX_projectile_dualgunBullet, boxSurfaces) < 0) return -1;
    if(Map::loadSurfaceT<CollideBoxType>("res/collideBox/projectile/Forge-collideBox-discBullet.png", COLBOX_projectile_discBullet, boxSurfaces) < 0) return -1;
    loadPixelFromSurface<CollideBoxType>(COLBOX_END, boxSurfaces, collideBoxes);
    return 0;
}

int CollideBox::initLevelCollideBoxes(){
    vector<SDL_Surface*> levelSurfaces;
    vector<vector<int>> levelboxes;
    if(Map::loadSurface("res/collideBox/level1/Layer 1.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 2.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 3.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 4.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 5.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 6.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 7.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level1/Layer 8.png", levelSurfaces) < 0) return -1;
    loadPixelFromSurface(levelSurfaces, levelboxes, vector2(gb::getWidth() / gb::getScale() / levelSurfaces[0]->w,gb::getHeight() / gb::getScale() / levelSurfaces[0]->h));
    levelSurfaces.clear();
    levelCollideBoxes[LEV_1] = levelboxes;
    levelboxes.clear();
    
    if(Map::loadSurface("res/collideBox/level2/Layer 1.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 2.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 3.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 4.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 5.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 6.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 7.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 8.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 9.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level2/Layer 10.png", levelSurfaces) < 0) return -1;
    loadPixelFromSurface(levelSurfaces, levelboxes, vector2(gb::getWidth() / gb::getScale() / levelSurfaces[0]->w,gb::getHeight() / gb::getScale() / levelSurfaces[0]->h));
    levelSurfaces.clear();
    levelCollideBoxes[LEV_2] = levelboxes;
    levelboxes.clear();

    if(Map::loadSurface("res/collideBox/level3/Layer 1.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 2.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 3.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 4.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 5.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 6.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 7.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 8.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 9.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 10.png", levelSurfaces) < 0) return -1;
    if(Map::loadSurface("res/collideBox/level3/Layer 11.png", levelSurfaces) < 0) return -1;
    loadPixelFromSurface(levelSurfaces, levelboxes, vector2(gb::getWidth() / gb::getScale() / levelSurfaces[0]->w,gb::getHeight() / gb::getScale() / levelSurfaces[0]->h));
    levelSurfaces.clear();
    levelCollideBoxes[LEV_3] = levelboxes;
    levelboxes.clear();
    
    return 0;
}

template<typename type>
void CollideBox::loadPixelFromSurface(int length, SDL_Surface** surfaces, vector<vector<int>>& boxes){
    // record the offsetX, offsetY, boxWidth, boxHeight of each surface's green box 
    for(type j=(type)0;j<(type)length;j=(type)(j+1)){
        SDL_Surface* surface = surfaces[j];
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
        offsetX *= gb::getScale();
        offsetY *= gb::getScale();
        boxWidth *= gb::getScale();
        boxHeight *= gb::getScale();
        box.push_back(offsetX); // at(0)
        box.push_back(offsetY); // at(1)
        box.push_back(boxWidth); // at(2)
        box.push_back(boxHeight); // at(3)
        boxes[j] = box;
    }
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

vector<int>* CollideBox::getCollideBox(CollideBoxType type){
    vector<int>* collideBox;
    collideBox = &collideBoxes[type];
    if(collideBox == nullptr) printf("Error: failed to get collideBox\nGetCollideBox Error: '%d'\n", type);
    return collideBox;
}

vector<vector<int>>* CollideBox::getLevelCollideBox(LevelType levelType){
    vector<vector<int>>* levelCollideBox;
    levelCollideBox = &levelCollideBoxes[levelType];
    if(levelCollideBox == nullptr) printf("Error: failed to get levelCollideBox\nGetLevelCollideLBox Error: '%d'\n", levelType);
    return levelCollideBox;
}

/*
        non-static part
*/

CollideBox::CollideBox(){
}

CollideBox::CollideBox(CollideBoxType boxType, vector2* pos, CollideType type){
    box = CollideBox::getCollideBox(boxType);
    this->entityPos = pos;
    this->collideType = type;
}

// for level box
CollideBox::CollideBox(vector<int>* box){
    this->box = box;
    this->collideType = COL_level;
}

void CollideBox::handleEvent(SDL_Event e){
    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.scancode == SDL_SCANCODE_C){
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