#pragma once
#include "headers/gb.h"
#include "headers/gameLoop/gameLoop.h"
#include "headers/allSprite.h"

class Playing : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
};