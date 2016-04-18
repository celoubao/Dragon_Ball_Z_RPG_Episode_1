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
    SimpleBattleLoop(LinkedList<Character> characters) : BattleLoop(characters) {
    }

    virtual void begin();

    virtual void end();

    virtual void goToNextCharacter();

    virtual void onNext(int index);

    void getUserInput(Character Character);

    void displayCharacterState(Character &character);

    void selectMove(Character &pCharacter);

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
    getUserInput(characters.get(index));
}

void SimpleBattleLoop::getUserInput(Character character) {
    displayCharacterState(character);
    selectMove(character);
}

void SimpleBattleLoop::displayCharacterState(Character &character) {
    cout << setw(20) << setfill('*') << " " << endl;
    for (int i = 0; i < characters.getSize(); ++i) {
        cout << characters.get(i).getName();
        if (i != characters.getSize() - 1) {
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

void SimpleBattleLoop::selectMove(Character &pCharacter) {
    int moveIndex;

    do {
        moveIndex = selectMoveForCharacter(pCharacter);
    }
    while(moveIndex == -1);

    int targetIndex = 0;

    Move* selectedMove = moves.get(moveIndex);

    if(selectedMove->needsTarget()) {
        do {
            targetIndex = selectTarget(pCharacter);
        } while (targetIndex >= characters.getSize() || targetIndex < 0 || targetIndex == characterIndex);

        Character target = characters.get(targetIndex);

        cout << pCharacter.getName() << " is attacking " << target.getName() << "!";
        waitForUser();

        if(selectedMove->getKiUsage() > pCharacter.getActualKI()) {
            cout << pCharacter.getName() << " tried to use " << selectedMove->getName() << " but it failed!" << endl;
        }
        else {
            selectedMove->use(&pCharacter, &target);
            characters.set(characterIndex, pCharacter);
            characters.set(targetIndex, target);
        }
        waitForUser();

        if (target.getActualHP() <= 0) {
            cout << target.getName() << " fainted!";
            waitForUser();
            cout << pCharacter.getName() << " won !";
            waitForUser();

            end();
            return;
        }
    }
    else {
        selectedMove->use(&pCharacter, &pCharacter);
        characters.set(characterIndex, pCharacter);
        waitForUser();
    }

    goToNextCharacter();
}

int SimpleBattleLoop::selectTarget(Character &character) {
    clearScreen();

    displayCharacterState(character);

    cout << "Select target" << endl;

    for (int i = 0; i < characters.getSize(); i++) {

        cout << i << " | ";

        if (i == characterIndex) {
            cout << "(You) ";
        }

        cout << characters.get(i).getName() << endl;
    }

    string input = getString();
    try {
        return stoi(input);
    }
    catch (invalid_argument &e) {
        return selectTarget(character);
    }
}



#endif //SIMPLE_BATTLE_LOOP_H
