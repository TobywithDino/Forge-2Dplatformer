#pragma once
#include "headers/gameLoop/menu.h"
#include "headers/gameLoop/playing.h"
#include "headers/gameLoop/gameOver.h"

class Game{
public:
    Game();
    int init();
    void start();
    void quit();
private:
    Menu menu = Menu();
    Playing playing = Playing();
    GameOver gameOver = GameOver();
};