//
// Created by cloubao on 4/21/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_FREEFORALL_H
#define DRAGON_BALL_Z_RPG_EDITION_FREEFORALL_H


#include <vector>
#include <iostream>
#include "FightMode.h"
#include "../../include/String.h"
#include "../loops/SimpleBattleLoop.h"
#include "../loops/CharacterSelectionScreen.h"
#include "../loops/MainScreen.h"

class FreeForAll : public FightMode {
public:

    FreeForAll() {
        modeName = "Free for all";
        description = "In this mode it's each fighter for himself ! The last fighter still alive wins!";
    }

    virtual void begin();

    virtual void end();

    void startBattleLoop(vector<Character *> &characters) {

        vector<Character> *chars = new vector<Character>();
        for (int i = 0; i < characters.size(); i++) {
            chars->push_back(*characters.at((i)));
        }

        SimpleBattleLoop battleLoop(*chars);
        bool restart;
        do {
            battleLoop.restart();
            cout << "Rematch? (Y)es / (N)o: ";
            string input = utils::toLowercase(getString());
            restart = input == "y" || input == "yes";
        } while (restart);

        end();
    }
};

void FreeForAll::begin() {
    GameSequence::begin();
    done = false;

    int numPlayers;
    do {
        clearScreen();
        cout << modeName << endl;
        cout << "How many players? [2-4]: ";
        numPlayers = getInt();
    } while (numPlayers < 2 || numPlayers > 4);

    CharacterSelectionScreen selectionScreen(numPlayers);
    selectionScreen.begin();

    vector<Character*> characters = selectionScreen.getCharacters();
    startBattleLoop(characters);
}

void FreeForAll::end() {
    GameSequence::end();
    done = true;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_FREEFORALL_H

