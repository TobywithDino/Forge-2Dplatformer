#pragma once
#include "headers/sound.h"

enum TextureType{
    TEX_sprite_testBlock,
    TEX_sprite_player,
    TEX_sprite_crawler,
    TEX_sprite_crawler_evolved,
    TEX_sprite_ploder,
    TEX_sprite_ploder_evolved,
    TEX_sprite_weaponBox,
    TEX_mapBrick_level1,
    TEX_mapBrick_level2,
    TEX_mapBrick_level3,
    TEX_map_level1,
    TEX_map_level2,
    TEX_map_level3,
    TEX_weapon_pistol,
    TEX_weapon_revolver,
    TEX_weapon_dualgun,
    TEX_weapon_disc,
    TEX_projt_pistolBullet,
    TEX_projt_revolverBullet,
    TEX_projt_dualgunBullet,
    TEX_projt_discBullet,
    TEX_button_start_unpressed,
    TEX_button_start_pressed,
    TEX_button_option_unpressed,
    TEX_button_option_pressed,
    TEX_button_quit_unpressed,
    TEX_button_quit_pressed,
    TEX_button_menu_pressed,
    TEX_button_menu_unpressed,
    TEX_button_music_unpressed,
    TEX_button_music_pressed,
    TEX_button_sfx_unpressed,
    TEX_button_sfx_pressed,
    TEX_button_selectLeft_unpressed,
    TEX_button_selectLeft_pressed,
    TEX_button_selectRight_unpressed,
    TEX_button_selectRight_pressed,
    TEX_button_play_unpressed,
    TEX_button_play_pressed,
    TEX_END
};

class Texture{
public:
    static int init();
    static SDL_Texture* getTexture(TextureType type);
    template<typename type>
    static int loadTexture(const char* path, type t, SDL_Texture** textures){
        SDL_Texture* tex;
        tex = IMG_LoadTexture(gb::getRenderer(), path);
        if(tex == nullptr){
            printf("Error: failed to load texture\nTexture Error: '%s'\n", path);
            return -1;
        }
        textures[t] = tex;
        return 0;
    }
private:
    static SDL_Texture* textures[TEX_END];
};