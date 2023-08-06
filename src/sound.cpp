#include "headers/sound.h"
Mix_Chunk* Sound::sfx[SFX_END];
Mix_Music* Sound::mus[MS_END];
int Sound::init(){
    if(loadSound("res/sound/sfx/Forge-sfx-weapon-disc.wav", SFX_weapon_disc, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-weapon-disc-bounce.wav", SFX_weapon_disc_bounce, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-weapon-pistol.wav", SFX_weapon_pistol, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-weapon-revolver.wav", SFX_weapon_revolver, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-weapon-dualgun.wav", SFX_weapon_dualgun, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-enemy-hurt.wav", SFX_enemy_hurt, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-enemy-dead.wav", SFX_enemy_dead, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-player-dead.wav", SFX_player_dead, sfx) < 0) return -1;
    if(loadSound("res/sound/sfx/Forge-sfx-player-pickWeapon.wav", SFX_player_pickWeapon, sfx) < 0) return -1;
    
    return 0;
}

void Sound::playSFX(SFXType type){
    if(sfx[type] == nullptr) return;
    if(type == SFX_END) return;
    Mix_PlayChannel(-1, sfx[type], 0);
}

void Sound::playMusic(MSType type){

}