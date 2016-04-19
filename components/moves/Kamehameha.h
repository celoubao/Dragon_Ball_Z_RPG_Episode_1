//
// Created by cloubao on 4/7/16.
//

#ifndef KAMEHAMEHA_H
#define KAMEHAMEHA_H

#include "../Character.h"
#include "../Move.h"

class Kamehameha : public DamageMove {
public:
    Kamehameha() {
        name = "Kamehameha";
        kiUsage = (long) KI_BAR;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};

void Kamehameha::use(Character *user, Character *target) {
    DamageMove::use(user, target);
}

float Kamehameha::getDamagePoints() {
    return LIFE_BAR / 3;
}

#endif //KAMEHAMEHA_H
