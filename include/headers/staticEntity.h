#pragma once
#include "headers/collision.h"

class StaticEntity : public Entity{
public:
    StaticEntity();
    StaticEntity(vector<int>* box);
    StaticEntity(vector2 pos, vector2 size = vector2(32,32));
    virtual void render() override;
private:
    bool show = true;
};