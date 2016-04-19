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
    int userIndex;
    int targetIndex;
};

class AttackSequence : public GameSequence {
public:
    AttackSequence(vector<Phase> &phases, vector<Character> &characters);

    virtual void begin();

    virtual void end();

private:
    vector<Character> *characters;
    vector<Phase> *phases;
};

AttackSequence::AttackSequence(vector<Phase> &phases, vector<Character> &characters) {
    this->phases = &phases;
    this->characters = &characters;
}

void AttackSequence::begin() {
    GameSequence::begin();

    cout << endl;

    Phase phase;
    for (int i = 0; i < phases->size(); i++) {

        phase = phases->at(i);

        Character *user = phase.user;
        Character *target = phase.target;
        Move *move = phase.move;

        if (phase.move->needsTarget()) {
            cout << user->getName() << " is attacking " << target->getName() << "!" << endl;
            if (move->getKiUsage() > user->getActualKI()) {
                cout << user->getName() << " tried to use " << move->getName() << " but it failed!" << endl;
            }
            else {
                move->use(user, target);
            }

            waitForUser();

            if (target->getActualHP() <= 0) {
                cout << target->getName() << " fainted!";
                waitForUser();
            }
        }
        else {
            move->use(user, target);
            waitForUser();
        }

        cout << endl;

        user->setActualKI(user->getActualKI() + user->getBonusKIPoints());

        characters->at(phase.userIndex) = *user;
        if (phase.targetIndex != -1) {
            characters->at(phase.targetIndex) = *target;
        }
    }
    end();
}

void AttackSequence::end() {
    GameSequence::end();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
