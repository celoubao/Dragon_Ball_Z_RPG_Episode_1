//
// Created by cloubao on 4/14/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_KIBLAST_H
#define DRAGON_BALL_Z_RPG_EDITION_KIBLAST_H


#include "../Move.h"

class KiBlast:  public PhysicalMove {
public:
    KiBlast() {
        name = "Ki Blast";
        kiUsage = (long) KI_BAR / 5;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getPhysicalDamagePoints();
};

void KiBlast::use(Character *user, Character *target) {
    PhysicalMove::use(user, target);
}

float KiBlast::getPhysicalDamagePoints() {
    return LIFE_BAR / 4;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_KIBLAST_H
