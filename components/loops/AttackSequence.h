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

    vector<Character> *getGraveyard();

private:
    vector<Character> *graveyard;
    vector<Phase> *phases;
    vector<Character> *characters;
};

AttackSequence::AttackSequence(vector<Phase> &phases, vector<Character> &characters) {
    this->graveyard = new vector<Character>();
    this->phases = &phases;
    this->characters = &characters;
}

vector<Character> *AttackSequence::getGraveyard() {
    return graveyard;
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

            if (phase.target->getActualHP() <= 0) {
                cout << phase.target->getName() << " is unable to fight!" << endl;
                characters->erase(characters->begin() + phase.targetIndex);
                graveyard->push_back(*phase.target);
                waitForUser();
                cout << endl;
            }

            if (phase.user->getActualHP() <= 0) {
                cout << phase.user->getName() << " is unable to fight!" << endl;
                graveyard->push_back(*phase.user);
                characters->erase(characters->begin() + phase.userIndex);
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
