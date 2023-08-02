#pragma once
#include "headers/gb.h"

enum TextureType{
    TEX_sprite_testBlock,
    TEX_sprite_player,
    TEX_sprite_crawler,
    TEX_sprite_crawler_evolved,
    TEX_sprite_ploder,
    TEX_sprite_ploder_evolved,
    TEX_sprite_weaponBox,
    TEX_map_level1,
    TEX_map_level2,
    TEX_weapon_pistol,
    TEX_weapon_revolver,
    TEX_weapon_dualgun,
    TEX_projt_pistolBullet,
    TEX_projt_revolverBullet,
    TEX_projt_dualgunBullet,
    TEX_END
};

class Texture{
public:
    static int init();
    static SDL_Texture* getTexture(TextureType type);
private:
    static SDL_Texture* textures[TEX_END];
    static vector<SDL_Texture*> spriteTextures;
    static vector<SDL_Texture*> levelTextures;
    static int loadTexture(const char* path, TextureType type);
};