//
// Created by Charles-Eugene Loubao on 4/21/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_BLOCK_H
#define DRAGON_BALL_Z_RPG_EDITION_BLOCK_H


#include "../Move.h"
#include "CharacterStates.h"

class Block : public Move {
public:
    Block() {
        name = "Block";
        kiUsage = KI_BAR / 4;
    }

    virtual void use(Character *user, Character *target);

    virtual bool affectsUserState();

    virtual bool needsTarget();

    virtual void onMoveFailed(Character *user);


};

void Block::use(Character *user, Character *target) {
    if (getKiUsage() > user->getActualKI()) {
        onMoveFailed(user);
        waitForUser();
        return;
    }
    user->setState(STATE_BLOCKING);
    onAffectUsersKI(user);
}

bool Block::needsTarget() {
    return false;
}

bool Block::affectsUserState() {
    return true;
}

void Block::onMoveFailed(Character *user) {
    cout << user->getName() << " is unable to protect itself!" << endl;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_BLOCK_H
