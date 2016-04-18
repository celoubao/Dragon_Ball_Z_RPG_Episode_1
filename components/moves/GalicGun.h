//
// Created by cloubao on 4/7/16.
//

#ifndef GALIC_GUN_H
#define GALIC_GUN_H

#include "../Move.h"
#include "../Character.h"

class GalicGun : public PhysicalMove {
public:
    GalicGun() {
        name = "Galic Gun";
        kiUsage = (long) KI_BAR;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getPhysicalDamagePoints();
};

void GalicGun::use(Character *user, Character *target) {
    PhysicalMove::use(user, target);
}

float GalicGun::getPhysicalDamagePoints() {
    return LIFE_BAR / 3;
}

#endif //GalicGun_H
