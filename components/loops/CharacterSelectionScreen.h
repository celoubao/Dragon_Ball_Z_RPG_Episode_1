//
// Created by cloubao on 4/15/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONSCREEN_H
#define DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONSCREEN_H


#include <iostream>
#include "GameSequence.h"
#include "../../linkedlist/LinkedList.h"
#include "../../include/Terminal.h"
#include "../GameData.h"
#include "../CharacterSelectionCallback.h"

class CharacterSelectionScreen: public GameSequence {
public:
    CharacterSelectionScreen(int numCharacters);
    virtual void begin();
    virtual void end();
    LinkedList<Character*> getCharacters();

private:
    int numCharacters;
    LinkedList<Character*> characters;
};

CharacterSelectionScreen::CharacterSelectionScreen(int numCharacters) {
    this->numCharacters = numCharacters;
}

void CharacterSelectionScreen::begin() {
    GameSequence::begin();
    for(int i = 0; i < numCharacters; i++) {
        clearScreen();
        cout << "Player " << i+1 << " select your Character!" << endl;
        characters.add(game::selectCharacter());
    }
    end();
}

void CharacterSelectionScreen::end() {
    GameSequence::end();
}

LinkedList<Character *> CharacterSelectionScreen::getCharacters() {
    return characters;
}

#endif //DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONSCREEN_H
