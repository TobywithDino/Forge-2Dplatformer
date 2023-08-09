#pragma once
#include "headers/staticEntity.h"

class Button : public StaticEntity{
public:
    Button();
    Button(vector2 pos, TextureType tType_unPress, TextureType tType_pressed, CollideBoxType cbType, vector2 size, GameState dstState = GS_END);

    void handleEvent(SDL_Event e) override;
    virtual void update() override;
    bool isPressing() {return pressing;}
    void rstPressing() {pressing = false;}
private:
    static bool holdingAButton;
    bool pressing = false; // holding
    TextureType unPressTex;
    TextureType pressedTex;
    GameState dstState = GS_END;
};