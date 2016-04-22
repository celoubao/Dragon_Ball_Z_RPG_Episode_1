//
// Created by cloubao on 4/8/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_VERSUS_SCREEN_H
#define DRAGON_BALL_Z_RPG_EDITION_VERSUS_SCREEN_H


#include <iostream>
#include <iomanip>
#include "GameSequence.h"
#include "../../include/Terminal.h"

class VersusScreen : public GameSequence {
public:
    VersusScreen(vector<Character> &characters);

    virtual void begin();

    virtual void end();

private:
    vector<Character> characters;

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

VersusScreen::VersusScreen(vector<Character> &characters) {
    this->characters = characters;
}

void VersusScreen::displayCharacters() {
    drawDivider();
    for (int i = 0; i < characters.size(); ++i) {
        cout << characters[i].getName();
        if (i != characters.size() - 1) {
            cout << " VS ";
        }
    }
    cout << endl;
    drawDivider();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_VERSUS_SCREEN_H
