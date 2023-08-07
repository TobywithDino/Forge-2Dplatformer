#pragma once
#include "headers/levelSpawner.h"

class Menu : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
    void init();
private:
    Button* menuButtons[3];
};