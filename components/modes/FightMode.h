//
// Created by cloubao on 4/21/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_SIMPLEFIGHTMODE_H
#define DRAGON_BALL_Z_RPG_EDITION_SIMPLEFIGHTMODE_H


#include "../loops/GameSequence.h"

class FightMode : public GameSequence {

protected:
    string modeName;
    bool done;

public:
    bool isDone() {
        return done;
    }

public:
    string getDescription() {
        return description;
    }

    string getModeName() {
        return modeName;
    }

protected:
    string description;
};


#endif //DRAGON_BALL_Z_RPG_EDITION_SIMPLEFIGHTMODE_H
