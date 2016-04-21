//
// Created by cloubao on 4/15/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_KICHARGE_H
#define DRAGON_BALL_Z_RPG_EDITION_KICHARGE_H


#include "../Move.h"
#include "KiBlast.h"

class KiCharge: public Move {
public:
    KiCharge() {
        name = "Charge KI";
        kiUsage = 0;
    }

    virtual bool needsTarget();
    virtual void use(Character *user, Character *target);
};

void KiCharge::use(Character *user, Character *target) {
    //Move::use(user, target);
    cout << user->getName() << " is Charging KI!" << endl;
    user->setActualKI(user->getActualKI() + (KI_BAR / 2), true);
}

bool KiCharge::needsTarget() {
    return false;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_KICHARGE_H
