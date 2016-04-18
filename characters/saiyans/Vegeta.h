//
// Created by cloubao on 4/7/16.
//

#ifndef VEGETA_H
#define VEGETA_H

#include "../Saiyan.h"

static const long VEGETA_ID = 2;


class Vegeta : public Saiyan {
public:
    Vegeta() {
        setName("Vegeta");
        setDefensePoints(0.05);
        setAttackPoints(0.5);
        resetCharacterStats();
    }
};


#endif //VEGETA_H
