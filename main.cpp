#include <iostream>
#include <iomanip>
#include "characters/saiyans/Goku.h"
#include "components/loops/SimpleBattleLoop.h"
#include "include/String.h"
#include "components/loops/MainScreen.h"
#include "components/GameData.h"
#include "components/loops/CharacterSelectionScreen.h"


using namespace std;

void startBattleLoop(vector<Character *> characters);

int main() {
    game::initializeGameData();

    MainScreen mainScreen;
    mainScreen.begin();

    CharacterSelectionScreen selectionScreen(2);
    selectionScreen.begin();

    startBattleLoop(selectionScreen.getCharacters());

    return 0;
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

}