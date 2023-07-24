#include "headers/player.h"

Player::Player(){
    Entity();
}

Player::Player(vector2 pos){
    Entity(pos, vector2(0,0), TEX_player);
}

void Player::handleEvent(){

}