#pragma once
#include "headers/gameLoop/option.h"

class SelectLevel : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
    void init();
private:
    LevelType level = LEV_1;
    Button* selectButtons[4];
    Text* t;
    StaticEntity* e;
};