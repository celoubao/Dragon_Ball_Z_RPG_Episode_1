//
// Created by cloubao on 4/8/16.
//

#ifndef DRAGON_BALL_Z_RPG_EDITION_RANDOMMOVE_H
#define DRAGON_BALL_Z_RPG_EDITION_RANDOMMOVE_H


#include "../Move.h"

class RandomMove : public PhysicalMove {
public:
    RandomMove() {
        name = "Random";
    }

    virtual float getPhysicalDamagePoints();
};

float RandomMove::getPhysicalDamagePoints() {
    int max = LIFE_BAR;
    long damagePoints = ((random() % max) + (random() % max)) / 2;

    cout << damagePoints << endl;
    return damagePoints;
}


#endif //DRAGON_BALL_Z_RPG_EDITION_RANDOMMOVE_H
