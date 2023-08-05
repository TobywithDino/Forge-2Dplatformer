#pragma once
#include "headers/texture.h"

enum AnimType{
    ANIM_crawler_walk,
    ANIM_crawler_evolved_walk,
    ANIM_ploder_walk,
    ANIM_player_idle,
    ANIM_player_walk,
    ANIM_END
};

enum AnimState{
    AS_idle,
    AS_walk,
    AS_jump,
    AS_END
};

class Anim{
// static part
public:
    static int init();
private:
    static SDL_Texture* getTexture(AnimType type) {return anims[type];}
    static SDL_Texture* anims[ANIM_END];
    
// non-static part
public:
    Anim();
    Anim(vector2 *pos, TextureType defaultTex, AnimType idle, AnimType walk, AnimType jump, bool on = true);
    Anim(vector2 *pos, TextureType defaultTex, AnimType idle, AnimType walk, AnimType jump, vector2 size, bool on = true);
    void render(double angle, SDL_RendererFlip flip);
    void setState(AnimState state);
    void setOnAnim(bool onAnim) {this->onAnim = onAnim;}
    bool getOnAnim() {return onAnim;}
private:
    bool onAnim = false;
    vector2* pos = new vector2(0,0);
    SDL_Texture* defaultTex;
    SDL_Texture* idle;
    SDL_Texture* walk;
    SDL_Texture* jump;
    AnimState state = AS_END;
    vector2 size = vector2(32,32) * gb::getScale();
    Uint64 lastTick = 0;
    int gapTicks = 150;
    int index = 0;
};