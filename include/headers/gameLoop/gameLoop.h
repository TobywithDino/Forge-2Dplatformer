#pragma once

class GameLoop{
public:
    virtual void handleEvent() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    static bool spawned;
};