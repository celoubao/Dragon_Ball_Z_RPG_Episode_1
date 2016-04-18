//
// Created by cloubao on 4/7/16.
//

#ifndef BROLY_H
#define BROLY_H

#include "../Saiyan.h"


static const long BROLY_ID = 0;

class Broly : public Saiyan {
public:
    Broly() {
        setName("Broly");
        setAttackPoints(0.8);
        setDefensePoints(0.3);
        setMaxHP(LIFE_BAR * 5);
        resetCharacterStats();
    }
};

#endif //GOKU_H
