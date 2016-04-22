#include <iostream>
#include <iomanip>
#include "characters/saiyans/Goku.h"
#include "components/loops/SimpleBattleLoop.h"
#include "include/String.h"
#include "components/loops/MainScreen.h"
#include "components/loops/CharacterSelectionScreen.h"


using namespace std;

void startBattleLoop(vector<Character *> characters);

void startGameLoop();

int main() {
    game::initializeGameData();

    startGameLoop();

    return 0;
}

void startGameLoop() {
    MainScreen mainScreen;
    mainScreen.begin();

    int numPlayers;
    do {
        clearScreen();
        cout << "Duel Mode" << endl;
        cout << "How many players? [2-4]: ";
        numPlayers = getInt();
    } while (numPlayers < 2 || numPlayers > 4);

    CharacterSelectionScreen selectionScreen(numPlayers);
    selectionScreen.begin();

    startBattleLoop(selectionScreen.getCharacters());
}

void startBattleLoop(vector<Character *> characters) {

    vector<Character> chars;
    for (int i = 0; i < characters.size(); i++) {
        chars.push_back(*characters[(i)]);
    }

    SimpleBattleLoop battleLoop(chars);
    bool restart;
    do {
        battleLoop.restart();
        cout << "Rematch? (Y)es / (N)o: ";
        string input = utils::toLowercase(getString());
        restart = input == "y" || input == "yes";
    } while (restart);

    startGameLoop();

}