//
// Created by cloubao on 4/8/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_VERSUS_SCREEN_H
#define DRAGON_BALL_Z_RPG_EDITION_VERSUS_SCREEN_H


#include <iostream>
#include <iomanip>
#include "GameSequence.h"
#include "../../include/Terminal.h"
#include "../../linkedlist/LinkedList.h"

class VersusScreen : public GameSequence {
public:
    VersusScreen(LinkedList<Character> characters);

    virtual void begin();

    virtual void end();

private:
    LinkedList<Character> characters;

    void displayCharacters();
};

void VersusScreen::begin() {
    GameSequence::begin();

    clearScreen();

    clearScreen();
    displayCharacters();

    waitForUser();

    end();

}

void VersusScreen::end() {
    GameSequence::end();
    clearScreen();
}

VersusScreen::VersusScreen(LinkedList<Character> characters) {
    this->characters = characters;
}

void VersusScreen::displayCharacters() {
    cout << setw(20) << setfill('*') << " " << endl;
    for (int i = 0; i < characters.getSize(); ++i) {
        cout << characters.get(i).getName();
        if (i != characters.getSize() - 1) {
            cout << " VS ";
        }
    }
    cout << endl << setw(20) << setfill('*') << " " << endl;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_VERSUS_SCREEN_H
