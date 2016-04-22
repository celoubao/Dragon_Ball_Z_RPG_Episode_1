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

    void onAffectTargetsHP(Character *pCharacter, Character *target);

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
        switch (target->getState()) {
            case STATE_BLOCKING:
                cout << target->getName() << " is protecting itself!" << endl;
                break;
            default:
                cout << user->getName() << " used " << name << "!" << endl;
                onAffectUsersKI(user);
                onAffectTargetsHP(user, target);
                break;
        }
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

void Move::onAffectTargetsHP(Character *pCharacter, Character *target) {

}

void Move::onMoveFailed(Character *user) {
    cout << user->getName() << " tried to use " << getName() << " but it failed!" << endl;
}


/**
 * A Damage Move is a move that affects the target's HP
 */
class DamageMove : public Move {
public:
    virtual void onAffectTargetsHP(Character *user, Character *target);

protected:
    virtual float getDamagePoints();
};


float DamageMove::getDamagePoints() {
    return 0;
}

void DamageMove::onAffectTargetsHP(Character *user, Character *target) {
    Move::onAffectTargetsHP(user, target);
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


#endif //MOVE_H
