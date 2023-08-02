#pragma once
#include "headers/movableEntity.h"
#include "headers/pistol.h"
#include "headers/revolver.h"
#include "headers/dualgun.h"

enum WeaponType{
    WP_pistol,
    WP_revolver,
    WP_dualgun,
    WP_END
};

class WeaponBox : public MovableEntity{
public:
    WeaponBox();
    WeaponBox(vector2 pos);
    Weapon* getWeapon(vector2 *playerPos);
    void update() override;
private:
    int ratio[WP_END] = {0};
    vector<WeaponType> dice;
    static WeaponType lastType;
};