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

    virtual bool affectsUserState();

    virtual long getKiUsage();

    string getName();

protected:
    long kiUsage;
    string name;

    void onAffectUsersKI(Character *user);

    virtual void onAffectTargetsHP(Character *pCharacter, Character *target, double d);

    virtual void onMoveFailed(Character *user);
};

string Move::getName() {
    return name;
}

void Move::use(Character *user, Character *target) {
    if (getKiUsage() > user->getActualKI()) {
        onMoveFailed(user);
        return;
    }
    if (needsTarget()) {
        double reductionPercentage = 0;
        switch (target->getState()) {
            case STATE_BLOCKING:
                reductionPercentage = 0.5f;
                cout << target->getName() << " is protecting itself!" << endl;
                break;
            default:
                cout << user->getName() << " used " << name << "!" << endl;
                break;
        }
        onAffectTargetsHP(user, target, reductionPercentage);
        onAffectUsersKI(user);
    }
    else {
        double remainingKI = user->getActualKI() - (kiUsage);
        user->setActualKI((long) remainingKI, true);
    }
}

long Move::getKiUsage() {
    return kiUsage;
}

bool Move::needsTarget() {
    return true;
}

bool Move::affectsUserState() {
    return false;
}

void Move::onAffectUsersKI(Character *user) {
    if (kiUsage > 0) {
        double remainingKI = user->getActualKI() - (kiUsage);
        user->setActualKI((long) remainingKI, true);
    }
}

void Move::onAffectTargetsHP(Character *pCharacter, Character *target, double d) {

}

void Move::onMoveFailed(Character *user) {
    cout << user->getName() << " tried to use " << getName() << " but it failed!" << endl;
}


/**
 * A Damage Move is a move that affects the target's HP
 */
class DamageMove : public Move {
public:
    virtual void onAffectTargetsHP(Character *user, Character *target, double reductionPercentage);

protected:
    virtual float getDamagePoints();
};


float DamageMove::getDamagePoints() {
    return 0;
}

void DamageMove::onAffectTargetsHP(Character *user, Character *target, double reductionPercentage) {
    Move::onAffectTargetsHP(user, target, 0);
    // We calculate the max damage the target is going to take;
    float initialDamagePoints = getDamagePoints();
    float damageBonus = initialDamagePoints * user->getAttack();
    float calculatedDamagePoints = initialDamagePoints + damageBonus;

    // Then we calculate how many points will be deducted from the damage points
    float targetDefense = target->getDefense();
    float damageReduction = calculatedDamagePoints * targetDefense;

    // Finally we subtract the reduction points from the damage points
    double damagePoints = calculatedDamagePoints - damageReduction;

    if(reductionPercentage > 0) {
        damagePoints -= (damagePoints * reductionPercentage);
    }

    // We reduce the target's Health Points
    target->setActualHP(target->getActualHP() - damagePoints);
}


#endif //MOVE_H
