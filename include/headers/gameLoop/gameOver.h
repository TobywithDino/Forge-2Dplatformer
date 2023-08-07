#pragma once
#include "headers/gameLoop/playing.h"


class GameOver : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
};