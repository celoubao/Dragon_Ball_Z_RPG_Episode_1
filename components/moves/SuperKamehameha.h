//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef SUPER_KAMEHAMEHA_H
#define SUPER_KAMEHAMEHA_H

#include "../Character.h"
#include "../Move.h"

class SuperKamehameha : public DamageMove {
public:
    SuperKamehameha() {
        name = "Super Kamehameha";
        kiUsage = KI_BAR * 2;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};

void SuperKamehameha::use(Character *user, Character *target) {
    DamageMove::use(user, target);
}

float SuperKamehameha::getDamagePoints() {
    return (float) (LIFE_BAR);
}

#endif //SUPER_KAMEHAMEHA_H
