//
// Created by cloubao on 4/8/16.
//

#ifndef BATTLELOOP_H
#define BATTLELOOP_H

#include <iostream>
#include <vector>
#include "GameSequence.h"
#include "../Character.h"
#include "../../characters/saiyans/Vegeta.h"
#include "VersusScreen.h"
#include "AttackSequence.h"

class BattleLoop : public GameSequence {

public:

    BattleLoop(vector <Character> &characters);

    virtual void begin();

    virtual void end();

    virtual void goToNextCharacter();

    virtual void onNext(int index);

    void restart();

protected:
    void onNewPhase(Phase phase);

    virtual void checkCharacterStatus(Character *character);

    long numCharacters;
    int characterIndex;
    vector <Character> characters;

private:
    AttackSequence *attackSequence = nullptr;
    vector <Phase> phases;
};

void BattleLoop::begin() {
    GameSequence::begin();

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
        attackSequence = new AttackSequence(phases, characters);
        attackSequence->begin();
        phases.clear();

        for (int i = 0; i < characters.size(); ++i) {
            cout << characters[i].getActualHP() << endl;
            waitForUser();
        }
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

BattleLoop::BattleLoop(vector <Character> &characters) {
    this->numCharacters = characters.size();
    this->characterIndex = -1;
    this->characters = characters;
}

void BattleLoop::restart() {
    for (int i = 0; i < characters.size(); ++i) {
        Character character = characters[i];
        character.resetCharacterStats();
        characters[i] = character;
    }
    characterIndex = -1;
    begin();
}

void BattleLoop::onNewPhase(Phase phase) {
    phases.push_back(phase);
}


#endif //BATTLELOOP_H
