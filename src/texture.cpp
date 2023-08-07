#include "headers/texture.h"

SDL_Texture* Texture::textures[TEX_END];

int Texture::init(){
    if(loadTexture("res/sprites/Forge-sprite-testBlock.png", TEX_sprite_testBlock, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-player.png", TEX_sprite_player, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-crawler.png", TEX_sprite_crawler, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-crawler_evolved.png", TEX_sprite_crawler_evolved, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-ploder.png", TEX_sprite_ploder, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-ploder_evolved.png", TEX_sprite_ploder_evolved, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-sprite-weaponBox.png", TEX_sprite_weaponBox, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-map-level1.png", TEX_map_level1, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-map-level2.png", TEX_map_level2, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-map-level3.png", TEX_map_level3, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-pistol.png", TEX_weapon_pistol, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-revolver.png", TEX_weapon_revolver, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-dualgun.png", TEX_weapon_dualgun, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-weapon-disc.png", TEX_weapon_disc, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-pistolBullet.png", TEX_projt_pistolBullet, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-revolverBullet.png", TEX_projt_revolverBullet, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-dualgunBullet.png", TEX_projt_dualgunBullet, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-projt-discBullet.png", TEX_projt_discBullet, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-button-start-unpressed.png", TEX_button_start_unpressed, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-button-start-pressed.png", TEX_button_start_pressed, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-button-option-unpressed.png", TEX_button_option_unpressed, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-button-option-pressed.png", TEX_button_option_pressed, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-button-quit-unpressed.png", TEX_button_quit_unpressed, textures) < 0) return -1;
    if(loadTexture("res/sprites/Forge-button-quit-pressed.png", TEX_button_quit_pressed, textures) < 0) return -1;
    return 0;
}

SDL_Texture* Texture::getTexture(TextureType type){
    SDL_Texture* tex;
    tex = textures[type];
    if(tex == nullptr) printf("Error: failed to get texture\nGetTexture Error: '%d'\n", type);
    return tex;
}