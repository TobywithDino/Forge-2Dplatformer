#include "headers/game.h"
#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

int main(int argc, char** argv){
    srand(time(NULL));
    Game game = Game();
    if(game.init() == 1) return 0;
    game.start();
    game.quit();
    return 0;
}