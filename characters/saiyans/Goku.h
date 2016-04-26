//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef GOKU_H
#define GOKU_H

#include "../Saiyan.h"
#include "../../components/moves/Kamehameha.h"
#include "../../components/moves/DeathBeam.h"
#include "../../components/moves/Kaioken.h"

class Goku : public Saiyan {
public:
    Goku() {

        CharacterStats characterStats;
        characterStats.attack = 0.3;
        characterStats.defense = 0.06;
        characterStats.bonusKI = 10;

        setName("Goku");
        initStats(characterStats);
    }

    virtual void addState(int state);

    virtual void onTurnEnded();

};

void Goku::onTurnEnded() {
    Character::onTurnEnded();
    int state = getState();

    if (state == state | STATE_KAIOKEN) {
        setActualKI((long) (getActualKI() - KAIOKEN_KI_REDUCTION), false);
        cout << getName() << " lost some KI!" << endl;
        waitForUser();

        if (getActualKI() <= 0) {
            removeState(STATE_KAIOKEN);
            cout << getName() << " is back to normal!" << endl;
            waitForUser();
        }
    }
}

void Goku::addState(int state) {
    Character::addState(state);
    CharacterStats *stats = getCurrentStats();

    switch (state) {
        case STATE_KAIOKEN:
            stats->attack += 0.1;
            stats->defense += 0.05;
            break;
        default:
            break;
    }
}


#endif //GOKU_H
