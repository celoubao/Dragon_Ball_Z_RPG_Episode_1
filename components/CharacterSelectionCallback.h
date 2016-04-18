//
// Created by cloubao on 4/15/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONCALLBACK_H
#define DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONCALLBACK_H

#include "Character.h"
#include "../linkedlist/LinkedList.h"

class CharacterSelectionCallback {
public:
    virtual void onCharacterListReady(LinkedList<Character*> characters);
};

void CharacterSelectionCallback::onCharacterListReady(LinkedList<Character *> characters) {

}

#endif //DRAGON_BALL_Z_RPG_EDITION_CHARACTERSELECTIONCALLBACK_H
