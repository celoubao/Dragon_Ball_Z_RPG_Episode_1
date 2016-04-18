//
// Created by cloubao on 4/8/16.
//

#ifndef BATTLELOOP_H
#define BATTLELOOP_H

#include <iostream>
#include "GameSequence.h"
#include "../Character.h"
#include "../../characters/saiyans/Vegeta.h"
#include "../../linkedlist/LinkedList.h"
#include "VersusScreen.h"
#include "AttackSequence.h"

class BattleLoop : public GameSequence {

public:

    BattleLoop(LinkedList<Character> characters);

    virtual void begin();

    virtual void end();

    virtual void goToNextCharacter();

    virtual void onNext(int index);

    void restart();

protected:
    void onNewPhase(Phase phase);
    virtual void checkCharacterStatus(Character *character);

    int numCharacters;
    int characterIndex;
    LinkedList<Character> characters;

private:
    AttackSequence* attackSequence = nullptr;
    LinkedList<Phase>* phases;
};

void BattleLoop::begin() {
    GameSequence::begin();

    phases = new LinkedList<Phase>();

    VersusScreen versusScreen(characters);
    versusScreen.begin();

    goToNextCharacter();
}

void BattleLoop::end() {
    GameSequence::end();
}

void BattleLoop::goToNextCharacter() {
    if (characterIndex == numCharacters - 1) {
        characterIndex = 0;
        attackSequence = new AttackSequence(phases,&characters);
        attackSequence->begin();
        phases->clear();
    }
    else {
        characterIndex += 1;
    }
    cout << characterIndex << endl;
    cout << numCharacters << endl;
    onNext(characterIndex);
}

void BattleLoop::onNext(int index) {

}

void BattleLoop::checkCharacterStatus(Character *character) {
}

BattleLoop::BattleLoop(LinkedList<Character> characters) {
    this->numCharacters = characters.getSize();
    this->characterIndex = -1;
    this->characters = characters;
}

void BattleLoop::restart() {
    for (int i = 0; i < characters.getSize(); ++i) {
        Character character = characters.get(i);
        character.resetCharacterStats();
        characters.set(i, character);
    }
    characterIndex = -1;
    begin();
}

void BattleLoop::onNewPhase(Phase phase) {
    phases->add(phase);
}


#endif //BATTLELOOP_H
