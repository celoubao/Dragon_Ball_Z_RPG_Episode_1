//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef KAMEHAMEHA_H
#define KAMEHAMEHA_H

#include "../Character.h"
#include "../Move.h"

class Kamehameha : public DamageMove {
public:
    Kamehameha() {
        name = "Kamehameha";
        kiUsage = KI_BAR / 2;
    }

    virtual void use(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};

void Kamehameha::use(Character *user, Character *target) {
    DamageMove::use(user, target);
}

float Kamehameha::getDamagePoints() {
    return (float) (LIFE_BAR - (LIFE_BAR * 0.25));
}

#endif //KAMEHAMEHA_H
