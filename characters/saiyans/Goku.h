//
// Created by cloubao on 4/7/16.
//

#ifndef GOKU_H
#define GOKU_H

#include "../Saiyan.h"
#include "../../components/moves/Kamehameha.h"
#include "../../components/moves/ErasorCannon.h"

static const long GOKU_ID = 1;

class Goku : public Saiyan {
public:

    Goku() {
        setName("Goku");
        setAttackPoints(0.6);
        setDefensePoints(0.04);
        resetCharacterStats();
    }
};

#endif //GOKU_H
