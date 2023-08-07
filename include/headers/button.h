#pragma once
#include "headers/staticEntity.h"

class Button : public StaticEntity{
public:
    Button();
    Button(vector2 pos, TextureType tType_unPress, TextureType tType_pressed, CollideBoxType cbType, vector2 size, GameState dstState);

    void handleEvent(SDL_Event e) override;
    virtual void update() override;
private:
    static bool holdingAButton;
    bool pressing = false;
    TextureType unPressTex;
    TextureType pressedTex;
    GameState dstState;
};