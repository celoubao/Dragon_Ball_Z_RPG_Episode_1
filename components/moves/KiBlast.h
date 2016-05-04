//
// Created by Charles-Eugene Loubao on 4/14/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_KIBLAST_H
#define DRAGON_BALL_Z_RPG_EDITION_KIBLAST_H


#include "../Move.h"

class KiBlast:  public DamageMove {
public:
    KiBlast() {
        name = "Ki Blast";
        kiUsage = (long) KI_BAR / 3;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};

void KiBlast::use(Character *user, Character *target) {
    DamageMove::use(user, target);
}

float KiBlast::getDamagePoints() {
    return LIFE_BAR / 4;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_KIBLAST_H
