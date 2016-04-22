//
// Created by cloubao on 4/8/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_MAINSCREEN_H
#define DRAGON_BALL_Z_RPG_EDITION_MAINSCREEN_H


#include <iostream>
#include <iomanip>
#include "GameSequence.h"
#include "../../include/Terminal.h"

const string GAME_NAME = "Dragon Ball Z :: RPG EDITION";

class MainScreen : public GameSequence {
public:
    virtual void begin();

    virtual void end();
};

void MainScreen::begin() {
    GameSequence::begin();
    clearScreen();
    cout << setw(GAME_NAME.length() + 5) << setfill('*') << " " << endl;
    cout << "* " << GAME_NAME << " *" << endl;
    cout << setw(GAME_NAME.length() + 5) << setfill('*') << " " << endl;

    waitForUser();

    end();

}

void MainScreen::end() {
    GameSequence::end();
    clearScreen();
}


#endif //DRAGON_BALL_Z_RPG_EDITION_MAINSCREEN_H
