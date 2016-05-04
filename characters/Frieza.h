//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef FRIEZA_H
#define FRIEZA_H

#include "Saiyan.h"

class Frieza : public Character {
public:
    Frieza() {

        CharacterStats characterStats;
        characterStats.attack = 0.2;
        characterStats.defense = 0.06;
        characterStats.bonusKI = 30;

        setName("Frieza");
        initStats(characterStats);
    }
};

#endif //FRIEZA_H
