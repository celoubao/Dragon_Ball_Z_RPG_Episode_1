//
// Created by cloubao on 4/18/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
#define DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H


#include "GameSequence.h"
#include "../Move.h"

struct Phase {
    Move move;
    Character target;
    Character user;
};

class AttackSequence: public GameSequence {
public:
    AttackSequence(Phase phases[]);
    virtual void begin();
    virtual void end();
private:
    Phase phases[];
};

AttackSequence::AttackSequence(Phase *phases) {
    this->phases = phases;
}

void AttackSequence::begin() {
    GameSequence::begin();

    for(Phase phase: phases) {

        Character user = phase.user;
        Character target = phase.target;
        Move move = phase.move;

        if(move.needsTarget()) {
            cout << user.getName() << " is attacking " << target.getName() << "!";
            waitForUser();

            if(move.getKiUsage() > user.getActualKI()) {
                cout << user.getName() << " tried to use " << move.getName() << " but it failed!" << endl;
            }
            else {
                move.use(&user, &target);;
            }

            waitForUser();

            if (target.getActualHP() <= 0) {
                cout << target.getName() << " fainted!";
                waitForUser();
            }
        }
        else {
            move.use(&user, &target);
        }
        waitForUser();
    }
    end();
}

void AttackSequence::end() {
    GameSequence::end();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
