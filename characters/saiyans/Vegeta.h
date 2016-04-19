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
        setDefense(0.05);
        setAttack(0.5);
        setBonusKIPoints(20);
        resetCharacterStats();
    }
};


#endif //VEGETA_H
