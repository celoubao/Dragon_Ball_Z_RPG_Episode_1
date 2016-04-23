//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef KAMEHAMEHA_H
#define KAMEHAMEHA_H

#include "../Character.h"
#include "../Move.h"

class SuperKamehameha : public DamageMove {
public:
    SuperKamehameha() {
        name = "Super Kamehameha";
        kiUsage = (long) KI_BAR;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};

void SuperKamehameha::use(Character *user, Character *target) {
    DamageMove::use(user, target);
}

float SuperKamehameha::getDamagePoints() {
    return LIFE_BAR;
}

#endif //KAMEHAMEHA_H
