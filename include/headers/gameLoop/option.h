#pragma once
#include "headers/gameLoop/gameOver.h"

class Option : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
    void init();
private:
    // attributes
};