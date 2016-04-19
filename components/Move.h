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
    if (kiUsage > 0) {
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
 * A Damage Move is a move that affects the target's HP
 */
class DamageMove : public Move {
public:
    virtual void use(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};

void DamageMove::use(Character *user, Character *target) {
    Move::use(user, target);

    // We calculate the max damage the target is going to take;
    float initialDamagePoints = getDamagePoints();
    float damageBonus = initialDamagePoints * user->getAttack();
    float calculatedDamagePoints = initialDamagePoints + damageBonus;

    // Then we calculate how many points will be deducted from the damage points
    float targetDefense = target->getDefense();
    float damageReduction = calculatedDamagePoints * targetDefense;

    // Finally we subtract the reduction points from the damage points
    double damagePoints = calculatedDamagePoints - damageReduction;

    // We reduce the target's Health Points
    target->setActualHP(target->getActualHP() - damagePoints);
}

float DamageMove::getDamagePoints() {
    return 0;
}

#endif //MOVE_H
