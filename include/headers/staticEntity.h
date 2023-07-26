#pragma once
#include "headers/entity.h"

class StaticEntity : public Entity{
public:
    StaticEntity();
    StaticEntity(vector<int>* box);
    virtual void render() override;
private:

};