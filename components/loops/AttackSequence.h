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
    vector<Character> *characters;
};

AttackSequence::AttackSequence(vector<Phase> &phases, vector<Character> &characters) {
    this->phases = &phases;
    this->characters = &characters;
}

void AttackSequence::begin() {
    GameSequence::begin();

    cout << endl;

    for (Phase phase: *phases) {

        // We skip the phase if the user is dead
        if (phase.userIndex >= characters->size() || phase.user != &characters->at(phase.userIndex)) {
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

            if (phase.user->getActualHP() == STATE_DEAD) {
                cout << phase.user->getName() << " is unable to fight!" << endl;
                waitForUser();
                cout << endl;
            }

            phase.target->resetState();
        }
        else {
            move->use(phase.user, phase.target);
            waitForUser();
        }

        cout << endl;

        phase.user->increaseKI();

        phase.user->resetState();
    }
    end();
}

void AttackSequence::end() {
    GameSequence::end();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
