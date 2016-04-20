/**
 * SimpleBattleLoop
 * In this mode each player attacks one after the other.
 * SimpleBattleLoop.end() will be called when one of the player is dead (fainted)
 */

#ifndef SIMPLE_BATTLE_LOOP_H
#define SIMPLE_BATTLE_LOOP_H

#include <cstdlib>
#include <stdexcept>
#include <cstring>

#include "../../include/Terminal.h"
#include "BattleLoop.h"
#include "../../characters/saiyans/Goku.h"
#include "../../characters/saiyans/Vegeta.h"
#include "../moves/RandomMove.h"
#include "../GameData.h"

using namespace std;
using namespace game;

class SimpleBattleLoop : public BattleLoop {

public:
    SimpleBattleLoop(vector<Character> &characters) : BattleLoop(characters) {
    }

    virtual void begin();

    virtual void end();

    virtual void goToNextCharacter();

    virtual void onNext(int index);

    void getUserInput(Character& Character);

    void displayCharacterState(Character &character);

    void selectMove(Character &user);

    int selectTarget(Character &character);

};

void SimpleBattleLoop::begin() {
    BattleLoop::begin();
}

void SimpleBattleLoop::end() {
    BattleLoop::end();
}

void SimpleBattleLoop::goToNextCharacter() {
    BattleLoop::goToNextCharacter();
}

void SimpleBattleLoop::onNext(int index) {
    clearScreen();
    BattleLoop::onNext(index);
    getUserInput(characters[index]);
}

void SimpleBattleLoop::getUserInput(Character& character) {
    selectMove(character);
}

void SimpleBattleLoop::displayCharacterState(Character &character) {
    cout << setw(20) << setfill('*') << " " << endl;
    for (int i = 0; i < characters.size(); ++i) {
        cout << characters[i].getName();
        if (i != characters.size() - 1) {
            cout << " VS ";
        }
    }
    cout << endl << setw(20) << setfill('*') << " " << endl;

    cout << "What should " << character.getName() << " do ?" << endl;
    cout << setw(20) << setfill('*') << " " << endl;
    cout << "HP: " << character.getActualHP() << "/" << character.getMaxHP() << endl;
    cout << "KI: " << character.getActualKI() << "/" << character.getMaxKI() << endl;
    cout << setw(20) << setfill('*') << " " << endl;

}

void SimpleBattleLoop::selectMove(Character &user) {
    int moveIndex;

    do {
        clearScreen();
        displayCharacterState(user);
        moveIndex = selectMoveForCharacter(user);
    }
    while (moveIndex == -1);

    Move *selectedMove = moves[(moveIndex)];

    int targetIndex = -1;

    if (selectedMove->needsTarget()) {
        do {
            targetIndex = selectTarget(user);
            if (targetIndex == characterIndex) {
                cout << endl << "Really -_- ? This is a serious fight! Stay focused! " << endl << endl;
                targetIndex = -1;
                waitForUser();
            }
        } while (targetIndex == -1);
    }

    Phase* phase = new Phase();
    phase->move = selectedMove;
    phase->user = &user;
    phase->target = &characters[targetIndex];

    onNewPhase(*phase);

    goToNextCharacter();
}

int SimpleBattleLoop::selectTarget(Character &character) {
    clearScreen();

    displayCharacterState(character);

    cout << "Select target" << endl;

    for (int i = 0; i < characters.size(); i++) {

        cout << i << " | ";

        if (i == characterIndex) {
            cout << "(You) ";
        }

        cout << characters[i].getName() << endl;
    }
    cout << setw(20) << setfill('*') << " " << endl;
    cout << "Enter value: ";
    string input = getString();
    try {
        return stoi(input);
    }
    catch (invalid_argument &e) {
        return selectTarget(character);
    }
}


#endif //SIMPLE_BATTLE_LOOP_H
