#pragma once
#include "headers/gameLoop/gameOver.h"

class Option : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
    void init();
private:
    Button* optionButtons[3];
    Text* optionTexts[2];
    int musPercent = 100;
    int sfxPercent = 100;
};