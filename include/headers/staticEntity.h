#pragma once
#include "headers/collision.h"

class StaticEntity : public Entity{
public:
    StaticEntity();
    StaticEntity(vector<int>* box);
    virtual void render() override;
private:
    bool show = true;
};