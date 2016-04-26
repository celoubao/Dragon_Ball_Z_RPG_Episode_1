//
// Created by Charles-Eugene Loubao on 4/18/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
#define DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H


#include "GameSequence.h"
#include "../Move.h"


struct Phase {
    Move *move;
    Character *target;
    Character *user;

    bool operator<(const Phase &phase) {
        return move->getPriority() < phase.move->getPriority();
    }

    bool operator>(const Phase &phase) {
        return move->getPriority() > phase.move->getPriority();
    }

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

        // We skip the phase if the user is dead
        if (phase.user->getState() == STATE_DEAD) {
            continue;
        }

        Move *move = phase.move;

        if (phase.move->needsTarget()) {
            cout << phase.user->getName() << " is attacking " << phase.target->getName() << "!" << endl;

            move->use(phase.user, phase.target);

            waitForUser();

            if (phase.target->getState() == STATE_DEAD) {
                cout << phase.target->getName() << " is unable to fight!" << endl;
                waitForUser();
                cout << endl;
            }
            else {
                phase.target->resetState();
            }

            if (phase.user->getActualHP() == STATE_DEAD) {
                cout << phase.user->getName() << " is unable to fight!" << endl;
                waitForUser();
                cout << endl;
            }

        }
        else {
            move->use(phase.user, phase.target);
            waitForUser();
        }

        phase.user->onTurnEnded();

        cout << endl;

    }
    end();
}

void AttackSequence::end() {
    GameSequence::end();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
