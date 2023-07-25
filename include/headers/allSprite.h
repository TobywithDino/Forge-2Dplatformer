#pragma once
#include "headers/player.h"

class AllSprite{
public:
    static int init();
    static vector<MovableEntity*>* getEntites() {return entities;}
    static MovableEntity* getPlayer() {return player;}
private:
    static vector<MovableEntity*>* entities;
    static MovableEntity* player;
};