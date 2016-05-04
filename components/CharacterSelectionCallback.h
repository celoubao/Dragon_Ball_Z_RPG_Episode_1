//
// Created by Charles-Eugene Loubao on 4/15/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONCALLBACK_H
#define DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONCALLBACK_H

#include "Character.h"

class CharacterSelectionCallback {
public:
    virtual void onCharacterListReady(vector<Character*> characters);
};

void CharacterSelectionCallback::onCharacterListReady(vector<Character *> characters) {

}

#endif //DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONCALLBACK_H
