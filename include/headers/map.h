#pragma once
#include "headers/texture.h"

enum LevelType{
    LEV_1,
    LEV_2,
    LEV_3,
    LEV_END
};

class Map{
public:
    static int init();
    static void render(int index);
    static int loadSurface(const char* path, vector<SDL_Surface*>& surfaces){
        SDL_Surface* surface;
        surface = IMG_Load(path);
        if(surface == nullptr){
            printf("Error: failed to load surface\nMap::init() Error: '%s'\n", path);
            return -1;
        }
        surfaces.push_back(surface);
        return 0;
    }

    template<typename type>
    static int loadSurfaceT(const char* path, type t, SDL_Surface** surfaces){
        SDL_Surface* surface;
        surface = IMG_Load(path);
        if(surface == nullptr){
            printf("Error: failed to load surface\nMap::init() Error: '%s'\n", path);
            return -1;
        }
        surfaces[t] = surface;
        return 0;
    }
private:
    static SDL_Surface* surfaces[LEV_END];
    static vector<vector<int>> levels;
};