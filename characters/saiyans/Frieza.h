//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef BROLY_H
#define BROLY_H

#include "../Saiyan.h"

class Frieza : public Saiyan {
public:
    Frieza() {
        setName("Frieza");
        setAttack(0.7);
        setDefense(0.06);
        setBonusKIPoints(30);
        resetCharacterStats();
    }
};

#endif //GOKU_H
