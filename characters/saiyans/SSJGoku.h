//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef SSJ_GOKU_H
#define SSJ_GOKU_H

#include "../Saiyan.h"
#include "../../components/moves/Kamehameha.h"
#include "../../components/moves/DeathBeam.h"

class SSJGoku : public Saiyan {
public:
    SSJGoku() {

        CharacterStats characterStats;
        characterStats.attack = 0.5;
        characterStats.defense = 0.07;
        characterStats.bonusKI = 30;

        setName("SSJ Goku");
        initStats(characterStats);
    }
};

#endif //SSJ_GOKU_H
