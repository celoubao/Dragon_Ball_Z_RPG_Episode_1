//
// Created by cloubao on 4/7/16.
//

#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include "Character.h"
#include "../include/Terminal.h"

using namespace std;

class Move {
public:
    virtual void use(Character *user, Character *target);
    virtual bool needsTarget();
    virtual long getKiUsage();
    string getName();

protected:
    long kiUsage;
    string name;
};

string Move::getName() {
    return name;
}

void Move::use(Character *user, Character *target) {
    cout << user->getName() << " used " << name << "!" << endl;
    if(kiUsage > 0) {
        double remainingKI = user->getActualKI() - (kiUsage);
        user->setActualKI((long) remainingKI);
    }
}

long Move::getKiUsage() {
    return kiUsage;
}

bool Move::needsTarget() {
    return true;
}


/**
 * A physical damage move is a move that affects the receiver's HP
 */
class PhysicalMove : public Move {
public:
    virtual void use(Character *user, Character *target);

protected:
    virtual float getPhysicalDamagePoints();
};

void PhysicalMove::use(Character *user, Character *target) {
    float physicalDamagePoints = getPhysicalDamagePoints();
    Move::use(user, target);
    float baseDamagePoints = physicalDamagePoints + (physicalDamagePoints * user->getAttackBonusPoints());

    double damagePoints = baseDamagePoints - (baseDamagePoints * (target->getDefensePoints()));

    if (damagePoints >= LIFE_BAR) {
        cout << "Critical hit !";
    }
    target->setActualHP(target->getActualHP() - damagePoints);
}

float PhysicalMove::getPhysicalDamagePoints() {
    return 0;
}

#endif //MOVE_H
