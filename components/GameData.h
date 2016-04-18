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
#include "../linkedlist/LinkedList.h"
#include "moves/KiBlast.h"
#include "../characters/saiyans/Broly.h"
#include "../characters/saiyans/Vegeta.h"
#include "../characters/saiyans/Goku.h"
#include "moves/KiCharge.h"

using namespace std;

int NUM_MOVES_PER_CHARACTER = 3;

namespace game {
    LinkedList<Character*> characters;
    LinkedList<Move*> moves;

    map<string,LinkedList<int>> moveSets;

    void initializeMoveList() {
        // All characters have those attacks
        moves.add(new KiCharge());
        moves.add((new KiBlast()));

        // Goku
        moves.add((new Kamehameha()));

        // Vegeta
        moves.add((new GalicGun()));

        // Broly
        moves.add((new EraserCannon()));
    }

    void initializeCharacterList() {

        characters.add((new Goku()));
        characters.add((new Vegeta()));
        characters.add((new Broly()));

        int moveIndex = 0;

        Character* character;
        for(int i = 0; i < characters.getSize(); i++) {
            character = characters.get(i);

            LinkedList<int> list;
            list.add(0);
            list.add(1);
            for(int j = list.getSize(); j< NUM_MOVES_PER_CHARACTER;j++) {
                moveIndex =  i+j; // j == 0 ? 0 : i+j
                list.add(moveIndex);
            }
            moveSets[character->getName()] = list;
        }
    }

    int selectMoveForCharacter(Character character) {
        int moveIndex;
        LinkedList<int> moveSet = moveSets[character.getName()];

        cout << "Moves:" << endl;
        cout << setw(20) << setfill('*') << " " << endl;

        Move* movePtr;
        for(int i = 0; i < moveSet.getSize(); i++) {
            movePtr = moves.get(moveSet.get(i));
            cout << i  << " | "<< movePtr->getName();

            if(movePtr->getKiUsage() > 0) {
                cout  << " (Requires " << movePtr->getKiUsage() << " Ki Points)"<< endl;
            }
            else {
                cout << endl;
            }
        }

        cout << setw(20) << setfill('*') << " " << endl;

        cout << "Select a move: ";
        cin >> moveIndex;
        return moveIndex < 0 || moveIndex >= moveSet.getSize() ? -1 : moveSet.get(moveIndex);
    }

    void initializeGameData() {
        initializeMoveList();
        initializeCharacterList();
    }

    Character *selectCharacter() {
        int index = 0;
        Character* character;

        for(int i = 0; i < characters.getSize(); i++) {
            cout << i << " | " << characters.get(i)->getName() << endl;
        }
        do {
            cout << "Enter value: ";
            index = getInt();
        }while(index < 0 || index >= characters.getSize());

        character = characters.get(index);

        return character;
    }
}

#endif //MOVES_H
