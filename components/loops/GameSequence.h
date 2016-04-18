//
// Created by cloubao on 4/8/16.
//

#ifndef GAMELOOP_H
#define GAMELOOP_H


#include "../Character.h"

class GameSequence {
public:
    virtual void begin();
    virtual void end();
};

void GameSequence::begin() {

}

void GameSequence::end() {

}

#endif //GAMELOOP_H
