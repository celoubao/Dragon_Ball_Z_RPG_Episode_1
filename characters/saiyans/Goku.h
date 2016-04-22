//
// Created by cloubao on 4/7/16.
//

#ifndef GOKU_H
#define GOKU_H

#include "../Saiyan.h"
#include "../../components/moves/Kamehameha.h"
#include "../../components/moves/ErasorCannon.h"

class Goku : public Saiyan {
public:

    Goku() {
        setName("Goku");
        setAttack(0.5);
        setDefense(0.04);
        setBonusKIPoints(20);
        resetCharacterStats();
    }
};

#endif //GOKU_H
