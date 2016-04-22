#include <iostream>
#include <iomanip>
#include "characters/saiyans/Goku.h"
#include "components/loops/SimpleBattleLoop.h"
#include "include/String.h"
#include "components/loops/MainScreen.h"
#include "components/loops/CharacterSelectionScreen.h"
#include "components/modes/FreeForAll.h"
#include "components/modes/ModeSelectionScreen.h"


void startGameLoop();

using namespace std;

int main() {
    game::initializeGameData();

    startGameLoop();

    return 0;
}

void startGameLoop() {
    vector<FightMode *> fightModes;
    fightModes.push_back(new FreeForAll());

    ModeSelectionScreen modeSelectionScreen(fightModes);
    do {
        modeSelectionScreen.begin();
    } while (modeSelectionScreen.getSelectedMode()->isDone());

}