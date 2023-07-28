#pragma once
#include "headers/gb.h"
#include "headers/gameLoop/gameLoop.h"


class GameOver : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
};