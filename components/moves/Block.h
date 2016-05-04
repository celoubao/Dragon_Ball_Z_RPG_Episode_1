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

    virtual bool needsTarget();

    virtual void onMoveFailed(Character *user);

    virtual int getPriority();


};

void Block::use(Character *user, Character *target) {
    cout << user->getName() << " is ready to block an attack !" << endl;
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

void Block::onMoveFailed(Character *user) {
    cout << user->getName() << " is unable to protect itself!" << endl;
}

int Block::getPriority() {
    return PRIORITY_STATE_CHANGE;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_BLOCK_H
