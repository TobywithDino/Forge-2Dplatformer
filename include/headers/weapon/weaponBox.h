#pragma once
#include "headers/movableEntity.h"
#include "headers/weapon/pistol.h"
#include "headers/weapon/revolver.h"
#include "headers/weapon/dualgun.h"
#include "headers/weapon/disc.h"

enum WeaponType{
    WP_pistol,
    WP_revolver,
    WP_dualgun,
    WP_disc,
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