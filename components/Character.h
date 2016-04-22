#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "../include/Terminal.h"

using namespace std;

static const int LIFE_BAR = 1000;
static const int KI_BAR = 500;

static const int STATE_IDLE = 0;
static const int STATE_BLOCKING = 1;

/**
 * Character Specifications:
 *
 * - Health Points (HP):    Represents the "life" of a character. When the HP equal 0 the character is considered "dead"
 *
 * - Attack:                A value between 0 and 1. Is a percentage of the base damage points of a Move (See Move.h)
 *                          that will be added to the move's damage points when used by this character.
 *
 * - Defense:               A value between 0 and 1. Is a percentage of the base damage points of a Move (See Move.h)
 *                          that will be subtracted from the moves's damage points calculated when taking damages
 *
 * - KI:                    Represent's the amount of energy a character has. Some moves requires a certain amount of KI
 *                          to be used. If the user attempt to use a move that requires more KI than his/her character has
 *                          the move will fail.
 *
 * - Bonus KI Points:       Amount of KI points that are added to the character's current KI points at the end of each turn
 *                          This value may vary depending on the character
 */
class Character {
protected:
    void setMaxHP(long maxHP);

    void setMaxKI(long maxKI);

    void setDefense(float defense);

    void setName(string name);

    void setAttack(float APS);

    void setBonusKIPoints(long bonusKIPoints);


public:
    Character();

    long getActualKI();

    void setActualKI(long ki, bool printMessage);

    long getMaxKI();

    long getBonusKIPoints();

    long getActualHP();

    long getMaxHP();

    float getDefense();

    float getAttack();

    string getName();

    void setActualHP(double hp);

    void resetCharacterStats();

    void increaseKI();

    int getState();

    void setState(int newState);

    void resetState();

private:
    string name;
    long maxHP;
    long actualHP;

    long actualKI = KI_BAR;
    long maxKI;
    long bonusKiPoints;

    float defense;
    float attack;

    int state = STATE_IDLE;
};

Character::Character() {
    setMaxHP(LIFE_BAR * 2);
    setMaxKI(KI_BAR * 3);
    resetCharacterStats();
}

void Character::setAttack(float attack) {
    this->attack = attack;
}


void Character::setName(string name) {
    this->name = name;
}

void Character::resetCharacterStats() {
    this->actualHP = this->maxHP;
    this->actualKI = KI_BAR;
}

void Character::setMaxHP(long maxHP) {
    this->maxHP = maxHP;
}

void Character::setDefense(float defense) {
    this->defense = defense;
}

string Character::getName() {
    return name;
}

long Character::getActualHP() {
    return actualHP;
}

float Character::getDefense() {
    return defense;
}

float Character::getAttack() {
    return attack;
}

void Character::setActualHP(double hp) {
    this->actualHP = hp;
}

long Character::getMaxHP() {
    return maxHP;
}

long Character::getActualKI() {
    return actualKI;
}

void Character::setActualKI(long ki, bool printMessage) {
    if (actualKI < maxKI || ki < maxKI) {
        this->actualKI = ki;
        if (actualKI >= maxKI) {
            actualKI = maxKI;
            if (printMessage) {
                cout << getName() << " is in Power Max Mode!" << endl;
            }
        }
    }
    else {
        if (printMessage) {
            cout << getName() << "'s KI cannot go higher!" << endl;
        }
    }
}

void Character::setMaxKI(long maxKI) {
    this->maxKI = maxKI;
}

long Character::getMaxKI() {
    return this->maxKI;
}

long Character::getBonusKIPoints() {
    return bonusKiPoints;
}

void Character::setBonusKIPoints(long bonusKIPoints) {
    this->bonusKiPoints = bonusKIPoints;
}

void Character::increaseKI() {
    setActualKI(getActualKI() + getBonusKIPoints(), false);
}

int Character::getState() {
    return state;
}

void Character::setState(int newState) {
    state = newState;
}

void Character::resetState() {
    state = STATE_IDLE;
}


#endif //CHARACTER_H
