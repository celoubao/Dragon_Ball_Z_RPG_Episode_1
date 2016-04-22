//
// Created by cloubao on 4/7/16.
//

#ifndef VEGETA_H
#define VEGETA_H

#include "../Saiyan.h"

class Vegeta : public Saiyan {
public:
    Vegeta() {
        setName("Vegeta");
        setAttack(0.5);
        setDefense(0.03);
        setBonusKIPoints(40);
        resetCharacterStats();
    }
};


#endif //VEGETA_H
