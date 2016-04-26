//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef VEGETA_H
#define VEGETA_H

#include "../Saiyan.h"

class Vegeta : public Saiyan {
public:
    Vegeta() {

        CharacterStats characterStats;
        characterStats.attack = 0.1;
        characterStats.defense = 0.03;
        characterStats.bonusKI = 40;

        setName("Vegeta");
        initStats(characterStats);
    }
};


#endif //VEGETA_H
