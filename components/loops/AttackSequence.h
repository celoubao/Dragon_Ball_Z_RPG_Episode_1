//
// Created by cloubao on 4/18/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
#define DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H


#include "GameSequence.h"
#include "../Move.h"

struct Phase {
    Move *move;
    Character *target;
    Character *user;
    bool targetKO = false;
    bool userKO = false;
    int targetIndex;
    int userIndex;
};

class AttackSequence : public GameSequence {
public:
    AttackSequence(vector<Phase> &phases, vector<Character> &characters);

    virtual void begin();

    virtual void end();

private:
    vector<Phase> *phases;
};

AttackSequence::AttackSequence(vector<Phase> &phases, vector<Character> &characters) {
    this->phases = &phases;
}

void AttackSequence::begin() {
    GameSequence::begin();

    cout << endl;

    for (Phase phase: *phases) {

        Move *move = phase.move;

        if (phase.move->needsTarget()) {
            cout << phase.user->getName() << " is attacking " << phase.target->getName() << "!" << endl;
            if (move->getKiUsage() > phase.user->getActualKI()) {
                cout << phase.user->getName() << " tried to use " << move->getName() << " but it failed!" << endl;
            }
            else {
                move->use(phase.user, phase.target);
            }

            waitForUser();

            if (phase.target->getActualHP() <= 0) {
                cout << phase.target->getName() << " is unable to fight!" << endl;
                phase.targetKO = true;
                waitForUser();
            }

            if (phase.user->getActualHP() <= 0) {
                cout << phase.user->getName() << " is unable to fight!" << endl;
                phase.userKO = true;
                waitForUser();
            }
        }
        else {
            move->use(phase.user, phase.target);
            waitForUser();
        }

        cout << endl;

        phase.user->setActualKI(phase.user->getActualKI() + phase.user->getBonusKIPoints());
    }
    end();
}

void AttackSequence::end() {
    GameSequence::end();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
