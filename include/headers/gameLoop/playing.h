#pragma once
#include "headers/gameLoop/menu.h"

class Playing : public GameLoop{
public:
    void handleEvent() override;
    void update() override;
    void render() override;
};