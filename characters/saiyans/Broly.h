//
// Created by cloubao on 4/7/16.
//

#ifndef BROLY_H
#define BROLY_H

#include "../Saiyan.h"

class Broly : public Saiyan {
public:
    Broly() {
        setName("Broly");
        setAttack(0.6);
        setDefense(0.1);
        setBonusKIPoints(1);
        setMaxKI(KI_BAR * 2);
        setMaxHP(LIFE_BAR * 5);
        resetCharacterStats();
    }
};

#endif //GOKU_H
