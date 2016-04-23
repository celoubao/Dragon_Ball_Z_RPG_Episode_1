//
// Created by Charles-Eugene Loubao on 4/21/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_MODESELECTIONSCREEN_H
#define DRAGON_BALL_Z_RPG_EDITION_MODESELECTIONSCREEN_H


#include <iostream>
#include <vector>
#include "../loops/GameSequence.h"
#include "FreeForAll.h"

class ModeSelectionScreen : GameSequence {
private:
    FightMode *selectedMode;
    vector<FightMode *> fightModes;

public:
    ModeSelectionScreen(vector<FightMode *> &fightmodes) {
        this->fightModes = fightmodes;
    }

    FightMode *getSelectedMode() {
        return selectedMode;
    }

    void begin() {
        GameSequence::begin();

        MainScreen mainScreen;
        mainScreen.begin();

        FightMode *fightMode;
        string modeIndex;

        int mode = -1;
        do {
            clearScreen();
            cout << "Which mode do you want to play ?" << endl << endl;
            for (int i = 0; i < fightModes.size(); i++) {
                fightMode = fightModes[i];
                cout << " " << i << " | " << fightMode->getModeName() << endl;
                cout << "     " << fightMode->getDescription() << endl;
                cout << endl;
            }
            cout << "Select a mode: ";
            mode = getInt();
        } while (mode < 0 || mode >= fightModes.size());

        selectedMode = fightModes[mode];
        selectedMode->begin();
    }
};

#endif //DRAGON_BALL_Z_RPG_EDITION_MODESELECTIONSCREEN_H
