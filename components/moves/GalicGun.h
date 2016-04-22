//
// Created by cloubao on 4/7/16.
//

#ifndef GALIC_GUN_H
#define GALIC_GUN_H

#include "../Move.h"
#include "../Character.h"

class GalicGun : public DamageMove {
public:
    GalicGun() {
        name = "Galic Gun";
        kiUsage = (long) KI_BAR / 2;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};

void GalicGun::use(Character *user, Character *target) {
    DamageMove::use(user, target);
}

float GalicGun::getDamagePoints() {
    return LIFE_BAR;
}

#endif //GalicGun_H
