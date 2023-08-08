#pragma once
#include "headers/text.h"

enum SFXType{
    SFX_weapon_disc,
    SFX_weapon_disc_bounce,
    SFX_weapon_pistol,
    SFX_weapon_revolver,
    SFX_weapon_dualgun,
    SFX_enemy_hurt,
    SFX_enemy_dead,
    SFX_player_dead,
    SFX_player_pickWeapon,
    SFX_END
};

enum MSType{
    MS_test,
    MS_END
};

class Sound{
public:
    static int init();
    static void playSFX(SFXType type);
    static void playMusic(MSType type);
    static void setSFXVolumn(int percent){
        sfx_volume = (MIX_MAX_VOLUME * percent) / 100;
    };
    static void setMusVolumn(int percent){
        mus_volume = (MIX_MAX_VOLUME * percent) / 100;
    }
private:
    static int loadSound(const char* path, SFXType type, Mix_Chunk** arr){
        Mix_Chunk* sfx;
        sfx = Mix_LoadWAV(path);
        if(sfx == nullptr) {
            printf("Error: failed to load SFX\nSound Error: '%s'\n", path);
            return -1;
        }
        arr[type] = sfx;
        return 0;
    }

    static int loadSound(const char* path, MSType type, Mix_Music** arr){
        Mix_Music* mus;
        mus = Mix_LoadMUS(path);
        if(mus == nullptr) {
            printf("Error: failed to load Music\nSound Error: '%s'\n", path);
            return -1;
        }
        arr[type] = mus;
        return 0;
    }
    static Mix_Chunk* sfx[SFX_END];
    static Mix_Music* mus[MS_END];
    static int sfx_volume;
    static int mus_volume;
};