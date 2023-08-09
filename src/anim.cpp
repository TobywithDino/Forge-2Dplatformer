#include "headers/anim.h"
SDL_Texture* Anim::anims[ANIM_END];

int Anim::init(){
    if(Texture::loadTexture("res/anim/Forge-anim-crawler-walk.png", ANIM_crawler_walk, anims) < 0) return -1;
    if(Texture::loadTexture("res/anim/Forge-anim-crawler_evolved-walk.png", ANIM_crawler_evolved_walk, anims) < 0) return -1;
    if(Texture::loadTexture("res/anim/Forge-anim-ploder-walk.png", ANIM_ploder_walk, anims) < 0) return -1;
    if(Texture::loadTexture("res/anim/Forge-anim-player-idle.png", ANIM_player_idle, anims) < 0) return -1;
    if(Texture::loadTexture("res/anim/Forge-anim-player-walk.png", ANIM_player_walk, anims) < 0) return -1;
    if(Texture::loadTexture("res/anim/Forge-anim-player-jump.png", ANIM_player_jump, anims) < 0) return -1;
    return 0;
}

Anim::Anim(){
}

Anim::Anim(vector2 *pos, TextureType defaultTex, AnimType idle, AnimType walk, AnimType jump, bool on){
    this->pos = pos;
    this->defaultTex = Texture::getTexture(defaultTex);
    if(idle == ANIM_END) this->idle = this->defaultTex;
    else this->idle = getTexture(idle);
    if(walk == ANIM_END) this->walk = this->defaultTex;
    else this->walk = getTexture(walk);
    if(jump == ANIM_END) this->jump = this->defaultTex;
    else this->jump = getTexture(jump);
    this->onAnim = on;
}

Anim::Anim(vector2 *pos, TextureType defaultTex, AnimType idle, AnimType walk, AnimType jump, vector2 size, bool on){
    this->pos = pos;
    this->defaultTex = Texture::getTexture(defaultTex);
    if(idle == ANIM_END) this->idle = this->defaultTex;
    else this->idle = getTexture(idle);
    if(walk == ANIM_END) this->walk = this->defaultTex;
    else this->walk = getTexture(walk);
    if(jump == ANIM_END) this->jump = this->defaultTex;
    else this->jump = getTexture(jump);
    this->size = size;
    this->onAnim = on;
}

void Anim::render(double angle, SDL_RendererFlip flip){
    // get current texture according to state
    SDL_Texture* texture = Texture::getTexture(TEX_sprite_testBlock); 
    switch (state)
    {
    case AS_idle:
        texture = idle;
        break;
    case AS_walk:
        texture = walk;
        break;
    case AS_jump:
        texture = jump;
        break;
    default:
        texture = defaultTex;
        break;
    }

    // get length of current animation
    int w = 1;
    SDL_QueryTexture(texture, NULL, NULL, &w, NULL);
    int length = 1;
    length = w / (int)size.x;
    if(length == 0) length = 1;
    
    // update frame of animation
    if(SDL_GetTicks64() - lastTick >= gapTicks){
        index++;
        index %= length;
        lastTick = SDL_GetTicks64();
    }

    // draw on screen
    SDL_Rect src,dst;
    src.w = size.x;
    src.h = size.y;
    src.x = size.x * index; 
    src.y = 0;
    dst.w = size.x*gb::getScale();
    dst.h = size.y*gb::getScale();
    dst.x = pos->x;
    dst.y = pos->y;
    SDL_RenderCopyEx(gb::getRenderer(), texture, &src, &dst, angle, NULL, flip);
}

void Anim::setState(AnimState state){
    if(state == this->state) return;
    else {
        this->state = state;
        index = 0;
    }
}