//
// Created by Charles-Eugene Loubao on 4/15/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONSCREEN_H
#define DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONSCREEN_H


#include <iostream>
#include "GameSequence.h"
#include "../../include/Terminal.h"
#include "../GameData.h"
#include "../CharacterSelectionCallback.h"

class CharacterSelectionScreen: public GameSequence {
public:
    CharacterSelectionScreen(int numCharacters);
    virtual void begin();
    virtual void end();
    vector<Character*> getCharacters();

private:
    int numCharacters;
    vector<Character*> characters;
};

CharacterSelectionScreen::CharacterSelectionScreen(int numCharacters) {
    this->numCharacters = numCharacters;
}

void CharacterSelectionScreen::begin() {
    GameSequence::begin();
    for(int i = 0; i < numCharacters; i++) {
        clearScreen();
        cout << "Player " << i+1 << " select your Character!" << endl << endl;
        characters.push_back(game::selectCharacter());
    }
    end();
}

void CharacterSelectionScreen::end() {
    GameSequence::end();
}

vector<Character *> CharacterSelectionScreen::getCharacters() {
    return characters;
}

#endif //DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONSCREEN_H
