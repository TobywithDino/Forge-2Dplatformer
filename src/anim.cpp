#include "headers/anim.h"
SDL_Texture* Anim::anims[ANIM_END];

int Anim::init(){
    if(Texture::loadTexture("res/anim/Forge-anim-crawler-walk.png", ANIM_crawler_walk, anims) < 0) return -1;
    if(Texture::loadTexture("res/anim/Forge-anim-crawler_evolved-walk.png", ANIM_crawler_evolved_walk, anims) < 0) return -1;
    if(Texture::loadTexture("res/anim/Forge-anim-ploder-walk.png", ANIM_ploder_walk, anims) < 0) return -1;
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

    vector2 originalSize = size / gb::getScale();
    // get length of current animation
    int w, length = 1;
    SDL_QueryTexture(texture, NULL, NULL, &w, NULL);
    length = w/(int)originalSize.x;
    if(length == 0) length = 1;
    
    // update frame of animation
    if(SDL_GetTicks64() - lastTick >= gapTicks){
        index++;
        index %= length;
        lastTick = SDL_GetTicks64();
    }

    // draw on screen
    SDL_Rect src,dst;
    src.w = originalSize.x;
    src.h = originalSize.y;
    src.x = originalSize.x * index; 
    src.y = 0;
    dst.w = size.x;
    dst.h = size.y;
    dst.x = pos->x;
    dst.y = pos->y;
    SDL_RenderCopyEx(gb::getRenderer(), texture, &src, &dst, angle, NULL, flip);
}