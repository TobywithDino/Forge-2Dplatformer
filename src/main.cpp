#include "headers/game.h"

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

int main(int argc, char** argv){
    
    Game game = Game(1280, 720, "Forge", true);
    if(game.init() == 1) return 0;
    return 0;
}