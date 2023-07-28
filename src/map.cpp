#include "headers/map.h"


vector<vector<int>> Map::levels;
vector<SDL_Surface*> Map::surfaces;

int Map::init(){
    // load png to surfaces
    if(loadSurface("res/maps/Forge-map-level1.png", surfaces) < 0) return -1;
    if(loadSurface("res/maps/Forge-map-level2.png", surfaces) < 0) return -1;
    if(loadSurface("res/maps/Forge-map-level3.png", surfaces) < 0) return -1;

    // convert each surface to int arrays and store in levels
    for(SDL_Surface* surface : surfaces){
        SDL_PixelFormat *fmt;
        Uint32 temp, pixel;
        Uint8 red;

        fmt = surface->format;
        int totalPixels = surface->w * surface->h;
        int maxLevelEntities = 0;
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
            if(red == 255){
                level.push_back(1);
                maxLevelEntities++;
            }
            else level.push_back(0);
        }
        level.push_back(maxLevelEntities);
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

void Map::render(int index){
    TextureType texType;
    switch (index)
    {
    case 0:
        texType = TEX_level_1;
        break;
    case 1:
        texType = TEX_level_2;
        break;
    default:
        texType = TEX_sprite_testBlock;
        break;
    }

    int mapWidth = levels[index][0];
    int mapHeight = levels[index][1];
    int pixelSizeW = gb::getWidth() / mapWidth;
    int pixelSizeH = gb::getHeight() / mapHeight; 
    for(int i=0;i<mapHeight;i++){
        for(int j=0;j<mapWidth;j++){
            if(i*mapWidth+j+2 > levels[index].size() - 1) continue;
            if(levels[index][i*mapWidth+j+2] == 0) continue;
            SDL_Rect dst;
            dst.w = pixelSizeW;
            dst.h = pixelSizeH;
            dst.x = j * pixelSizeW;
            dst.y = i * pixelSizeH;
            SDL_RenderCopy(gb::getRenderer(), Texture::getTexture(texType), NULL, &dst);
        }
    }

}