#include "headers/map.h"

SDL_Surface* Map::surfaces[LEV_END];
vector<vector<int>> Map::levels = vector<vector<int>>(LEV_END);
LevelType Map::levelType = LEV_1;

int Map::init(){
    // load png to surfaces
    if(loadSurfaceT<LevelType>("res/maps/Forge-map-level1.png", LEV_1, surfaces) < 0) return -1;
    if(loadSurfaceT<LevelType>("res/maps/Forge-map-level2.png", LEV_2, surfaces) < 0) return -1;
    if(loadSurfaceT<LevelType>("res/maps/Forge-map-level3.png", LEV_3, surfaces) < 0) return -1;

    // convert each surface to int arrays and store in levels
    for(LevelType i=LEV_1;i<LEV_END;i=(LevelType)(i+1)){
        SDL_Surface* surface = surfaces[i];
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
            if(red == 255){
                level.push_back(1);
            }
            else level.push_back(0);
        }
        levels[i] = level;
    }

    return 0;
}

void Map::render(){
    TextureType texType;
    switch (levelType)
    {
    case LEV_1:
        texType = TEX_map_level1;
        break;
    case LEV_2:
        texType = TEX_map_level2;
        break;
    case LEV_3:
        texType = TEX_map_level3;
        break;
    default:
        texType = TEX_sprite_testBlock;
        break;
    }

    int mapWidth = levels[levelType][0];
    int mapHeight = levels[levelType][1];
    int pixelSizeW = gb::getWidth() / mapWidth;
    int pixelSizeH = gb::getHeight() / mapHeight; 
    for(int i=0;i<mapHeight;i++){
        for(int j=0;j<mapWidth;j++){
            if(i*mapWidth+j+2 > levels[levelType].size() - 1) continue;
            if(levels[levelType][i*mapWidth+j+2] == 0) continue;
            SDL_Rect dst;
            dst.w = pixelSizeW;
            dst.h = pixelSizeH;
            dst.x = j * pixelSizeW;
            dst.y = i * pixelSizeH;
            SDL_RenderCopy(gb::getRenderer(), Texture::getTexture(texType), NULL, &dst);
        }
    }

}