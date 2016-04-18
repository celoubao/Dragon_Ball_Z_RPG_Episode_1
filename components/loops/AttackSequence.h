//
// Created by cloubao on 4/18/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
#define DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H


#include "GameSequence.h"
#include "../Move.h"
#include "../../linkedlist/LinkedList.h"

struct Phase {
    Move* move;
    Character* target;
    Character* user;
    int userIndex;
    int targetIndex;
};

class AttackSequence: public GameSequence {
public:
    AttackSequence(LinkedList<Phase>* phases, LinkedList<Character>* characters);
    virtual void begin();
    virtual void end();
private:
    LinkedList<Character>* characters;
    LinkedList<Phase>* phases;
};

AttackSequence::AttackSequence(LinkedList<Phase>* phases, LinkedList<Character>* characters) {
    this->phases = phases;
    this->characters = characters;
}

void AttackSequence::begin() {
    GameSequence::begin();


    Phase phase;
    for(int i = 0; i < phases->getSize(); i++) {

        phase = phases->get(i);

        Character* user = phase.user;
        Character* target = phase.target;
        Move* move  = phase.move;

        if(phase.move->needsTarget()) {
            cout << user->getName() << " is attacking " << target->getName() << "!";
            waitForUser();

            if(move->getKiUsage() > user->getActualKI()) {
                cout << user->getName() << " tried to use " << move->getName() << " but it failed!" << endl;
            }
            else {
                move->use(user, target);;
            }

            waitForUser();

            if (target->getActualHP() <= 0) {
                cout << target->getName() << " fainted!";
                waitForUser();
            }
        }
        else {
            move->use(user, target);
        }

        characters->set(phase.userIndex, *user);
        if(phase.targetIndex != -1) {
            characters->set(phase.targetIndex, *target);
        }

    }
    end();
}

void AttackSequence::end() {
    GameSequence::end();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_ATTACKSEQUENCE_H
