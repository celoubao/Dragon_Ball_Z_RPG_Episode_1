//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef DEATH_BEAM_H
#define DEATH_BEAM_H

#include "../Move.h"
#include "../Character.h"

class DeathBeam : public DamageMove {
public:
    DeathBeam() {
        name = "Death Beam";
        kiUsage = KI_BAR;
    }

    virtual void use(Character *user, Character *target);

public:
    virtual float getDamagePoints();
};

void DeathBeam::use(Character *user, Character *target) {
    DamageMove::use(user, target);
}

float DeathBeam::getDamagePoints() {
    return LIFE_BAR - (LIFE_BAR / 3);
}

#endif //ERASER_CANNON_H
