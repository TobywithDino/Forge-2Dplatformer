#include "headers/weaponBox.h"
WeaponType WeaponBox::lastType = WP_END;

WeaponBox::WeaponBox() : MovableEntity(){
    ratio[WP_pistol] = 1;
    ratio[WP_revolver] = 1;
    ratio[WP_dualgun] = 1;
    for(WeaponType i=WP_pistol;i<WP_END;i=(WeaponType)(i+1)){
        for(int j=0;j<ratio[i];j++){
            dice.push_back(i);
        }
    }
}

WeaponBox::WeaponBox(vector2 pos) : MovableEntity(pos, TEX_sprite_weaponBox, COLBOX_sprite_weaponBox, COL_weaponBox){
    ratio[WP_pistol] = 1;
    ratio[WP_revolver] = 1;
    ratio[WP_dualgun] = 1;
    for(WeaponType i=WP_pistol;i<WP_END;i=(WeaponType)(i+1)){
        for(int j=0;j<ratio[i];j++){
            dice.push_back(i);
        }
    }
}

Weapon* WeaponBox::getWeapon(vector2 *playerPos){
    WeaponType type;
    type = dice[rand()%dice.size()];
    while(type == lastType){
        type = dice[rand()%dice.size()];
    }
    lastType = type;

    Weapon* w;
    switch (type)
    {
    case WP_pistol:
        w = new Pistol(playerPos);
        break;
    case WP_revolver:
        w = new Revolver(playerPos);
        break;
    case WP_dualgun:
        w = new Dualgun(playerPos);
        break;
    default:
        printf("Error: WeaponBox::getWeapon : couldn't get weapon %d\n", type);
        break;
    }
    return w;
}

void WeaponBox::update(){
    if(pos.y >= gb::getHeight()){
        setActive(false);
    }
    MovableEntity::update();
}