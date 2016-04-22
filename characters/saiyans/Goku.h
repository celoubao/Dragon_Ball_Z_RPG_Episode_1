//
// Created by cloubao on 4/7/16.
//

#ifndef GOKU_H
#define GOKU_H

#include "../Saiyan.h"
#include "../../components/moves/SuperKamehameha.h"
#include "../../components/moves/DeathBeam.h"

class Goku : public Saiyan {
public:
    Goku() {
        setName("SSJ Goku");
        setAttack(0.8);
        setDefense(0.06);
        setBonusKIPoints(25);
        resetCharacterStats();
    }
};

#endif //GOKU_H
