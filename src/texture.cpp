#include "headers/texture.h"

vector<SDL_Texture*> Texture::spriteTextures;
vector<SDL_Texture*> Texture::levelTextures;
SDL_Texture* Texture::textures[TEX_END];

int Texture::init(){
    if(loadTexture("res/sprites/Forge-sprite-testBlock.png", TEX_sprite_testBlock) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-player.png", TEX_sprite_player) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-crawler.png", TEX_sprite_crawler) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-crawler_evolved.png", TEX_sprite_crawler_evolved) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-ploder.png", TEX_sprite_ploder) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-ploder_evolved.png", TEX_sprite_ploder_evolved) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-weaponBox.png", TEX_sprite_weaponBox) < 0) return -1;
    if(loadTexture("res/sprites/Forge-map-level1.png", TEX_map_level1) < 0) return -1;
    if(loadTexture("res/sprites/Forge-map-level2.png", TEX_map_level2) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-pistol.png", TEX_weapon_pistol) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-revolver.png", TEX_weapon_revolver) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-dualgun.png", TEX_weapon_dualgun) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-disc.png", TEX_weapon_disc) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-pistolBullet.png", TEX_projt_pistolBullet) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-revolverBullet.png", TEX_projt_revolverBullet) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-dualgunBullet.png", TEX_projt_dualgunBullet) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-discBullet.png", TEX_projt_discBullet) < 0) return -1;
    return 0;
}

SDL_Texture* Texture::getTexture(TextureType type){
    SDL_Texture* tex;
    tex = textures[type];
    if(tex == nullptr) printf("Error: failed to get texture\nGetTexture Error: '%d'\n", type);
    return tex;
}

int Texture::loadTexture(const char* path, TextureType type){
    SDL_Texture* tex;
    tex = IMG_LoadTexture(gb::getRenderer(), path);
    if(tex == nullptr){
        printf("Error: failed to load texture\nTexture Error: '%s'\n", path);
        return -1;
    }
    textures[type] = tex;
    return 0;
}