//
// Created by cloubao on 4/7/16.
//

#ifndef ERASER_CANNON_H
#define ERASER_CANNON_H

#include "../Move.h"
#include "../Character.h"

class EraserCannon : public PhysicalMove {
public:
    EraserCannon() {
        name = "Eraser Cannon";
        kiUsage = KI_BAR + (KI_BAR / 2);
    }

    virtual void use(Character *user, Character *target);

public:
    virtual float getPhysicalDamagePoints();
};

void EraserCannon::use(Character *user, Character *target) {
    PhysicalMove::use(user, target);
}

float EraserCannon::getPhysicalDamagePoints() {
    return LIFE_BAR;
}

#endif //ERASER_CANNON_H
