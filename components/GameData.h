//
// Created by cloubao on 4/7/16.
//

#ifndef MOVES_H
#define MOVES_H

#include <map>
#include <string>
#include <iomanip>

#include "Move.h"
#include "moves/Kamehameha.h"
#include "moves/ErasorCannon.h"
#include "moves/GalicGun.h"
#include "moves/KiBlast.h"
#include "../characters/saiyans/Broly.h"
#include "../characters/saiyans/Vegeta.h"
#include "../characters/saiyans/Goku.h"
#include "moves/KiCharge.h"
#include "moves/Block.h"

using namespace std;

int NUM_MOVES_PER_CHARACTER = 4;

namespace game {
    vector<Character *> characters;
    vector<Move *> moves;

    map<string, vector<int>> moveSets;

    void initializeMoveList() {
        // All characters have those moves
        moves.push_back(new KiCharge());
        moves.push_back((new KiBlast()));
        moves.push_back((new Block()));

        // Goku
        moves.push_back((new Kamehameha()));

        // Vegeta
        moves.push_back((new GalicGun()));

        // Broly
        moves.push_back((new EraserCannon()));
    }

    void initializeCharacterList() {

        characters.push_back((new Goku()));
        characters.push_back((new Vegeta()));
        characters.push_back((new Broly()));

        int moveIndex = 0;

        Character *character;
        for (int i = 0; i < characters.size(); i++) {
            character = characters[i];

            vector<int> list;
            list.push_back(0);
            list.push_back(1);
            list.push_back(2);

            for (int j = list.size(); j < NUM_MOVES_PER_CHARACTER; j++) {
                moveIndex = i + j; // j == 0 ? 0 : i+j
                list.push_back(moveIndex);
            }
            moveSets[character->getName()] = list;
        }
    }

    int selectMoveForCharacter(Character character) {
        int moveIndex;
        vector<int> moveSet = moveSets[character.getName()];

        cout << "Moves:" << endl;
        cout << setw(20) << setfill('*') << " " << endl;

        Move *movePtr;
        for (int i = 0; i < moveSet.size(); i++) {
            movePtr = moves[(moveSet[i])];
            cout << i << " | " << movePtr->getName();

            if (movePtr->getKiUsage() > 0) {
                cout << " (Requires " << movePtr->getKiUsage() << " Ki Points)" << endl;
            }
            else {
                cout << endl;
            }
        }

        cout << setw(20) << setfill('*') << " " << endl;

        cout << "Select a move: ";
        moveIndex = getInt();
        return moveIndex < 0 || moveIndex >= moveSet.size() ? -1 : moveSet[(moveIndex)];
    }

    void initializeGameData() {
        initializeMoveList();
        initializeCharacterList();
    }

    Character *selectCharacter() {
        int index = 0;
        Character *character;

        for (int i = 0; i < characters.size(); i++) {
            cout << i << " | " << characters[i]->getName() << endl;
        }
        do {
            cout << "Enter value: ";
            index = getInt();
        } while (index < 0 || index >= characters.size());

        character = characters[index];

        return character;
    }
}

#endif //MOVES_H
