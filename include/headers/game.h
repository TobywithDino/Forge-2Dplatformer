#pragma once
#include "headers/gameLoop/menu.h"
#include "headers/gameLoop/playing.h"
#include "headers/gameLoop/gameOver.h"
#include "headers/gameLoop/option.h"
#include "headers/gameLoop/selectLevel.h"

class Game{
public:
    Game();
    int init();
    void start();
    void quit();
private:
    Menu menu = Menu();
    Option option = Option();
    SelectLevel selectLevel = SelectLevel();
    Playing playing = Playing();
    GameOver gameOver = GameOver();
};