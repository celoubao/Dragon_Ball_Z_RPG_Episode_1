//
// Created by Charles-Eugene Loubao on 4/26/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_KAIOKEN_H
#define DRAGON_BALL_Z_RPG_EDITION_KAIOKEN_H

#include "../Move.h"

const float KAIOKEN_KI_REDUCTION = KI_BAR / 5;

class Kaioken : public Move {
public:

    Kaioken() {
        name = "Kaioken";
        kiUsage = KI_BAR;
    }

    virtual bool needsTarget();

    virtual void use(Character *user, Character *target);
};

bool Kaioken::needsTarget() {
    return false;
}

void Kaioken::use(Character *user, Character *target) {
    Move::use(user, target);
    user->addState(STATE_KAIOKEN);

    cout << user->getName() << " used " << getName() << endl;
    cout << user->getName() << "'s attack and defense have been boosted !" << endl;

    waitForUser();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_KAIOKEN_H
