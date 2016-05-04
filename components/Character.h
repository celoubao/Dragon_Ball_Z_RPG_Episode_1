#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "../include/Terminal.h"
#include "moves/CharacterStates.h"

using namespace std;

static const int LIFE_BAR = 1000;
static const int KI_BAR = 500;

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
 *                          When a Character's KI is at its maximum value, the user enter's in Power Max.
 *                          In this mode, the user's attack increases by 2%
 *
 * - Bonus KI:       Amount of KI points that are added to the character's current KI points at the end of each turn
 *                          This value may vary depending on the character
 */

struct CharacterStats {
    float attack = 0;
    float defense = 0;
    double actualHP = 0;
    long maxHP = LIFE_BAR * 3;
    long actualKI = KI_BAR;
    long maxKI = KI_BAR * 3;
    long bonusKI = 0;

    CharacterStats &operator=(const CharacterStats &characterStats) {
        this->attack = characterStats.attack;
        this->defense = characterStats.defense;
        this->actualHP = characterStats.actualHP;
        this->maxHP = characterStats.maxHP;
        this->actualKI = characterStats.actualKI;
        this->maxKI = characterStats.maxKI;
        this->bonusKI = characterStats.bonusKI;
        return *this;
    }

};

class Character {
protected:

    void setName(string name);

    void initStats(CharacterStats &baseStats);

    CharacterStats *getCurrentStats();

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


    virtual void addState(int newState);

    void removeState(const int kaioken);

private:

public:

    virtual void onTurnEnded();

private:
    int kiReduction = -1;

    string name;

    int state = STATE_IDLE;

    CharacterStats *defaultStats = new CharacterStats();
    CharacterStats *currentStats = new CharacterStats();

    void onPowerMaxMode();

    void onNormalMode();
};

Character::Character() {
    resetCharacterStats();
}


void Character::setName(string name) {
    this->name = name;
}

void Character::resetCharacterStats() {
    resetState();
    this->currentStats = this->defaultStats;
    this->currentStats->actualKI = defaultStats->maxKI / 2;
    this->currentStats->actualHP = this->defaultStats->maxHP;
}

string Character::getName() {
    return name;
}

long Character::getActualHP() {
    return (long) this->currentStats->actualHP;
}

float Character::getDefense() {
    return this->currentStats->defense;
}

float Character::getAttack() {
    return this->currentStats->attack;
}

void Character::setActualHP(double hp) {
    this->currentStats->actualHP = hp;
    if (this->currentStats->actualHP <= 0) {
        this->state = STATE_DEAD;
    }
}

long Character::getMaxHP() {
    return this->currentStats->maxHP;
}

long Character::getActualKI() {
    return this->currentStats->actualKI;
}

void Character::setActualKI(long ki, bool printMessage) {
    long actualKI = this->currentStats->actualKI;
    long maxKI = this->currentStats->maxKI;

    if (actualKI < maxKI || ki < maxKI) {
        actualKI = ki;
        if (actualKI >= maxKI) {
            actualKI = maxKI;
            onPowerMaxMode();
            if (printMessage) {
                cout << getName() << " is in Power Max Mode!" << endl;
            }
        }
        else {
            onNormalMode();
        }

        this->currentStats->actualKI = actualKI;
    }
    else {
        if (printMessage) {
            cout << getName() << "'s KI cannot go higher!" << endl;
        }
    }
}

long Character::getMaxKI() {
    return this->currentStats->maxKI;
}

long Character::getBonusKIPoints() {
    return this->currentStats->bonusKI;
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

void Character::addState(int newState) {
    state = state | newState;
}

void Character::resetState() {
    state = STATE_IDLE;
}

void Character::initStats(CharacterStats &baseStats) {
    *this->defaultStats = baseStats;
    resetCharacterStats();
}

void Character::onPowerMaxMode() {
    this->currentStats->attack += 0.02;
}

void Character::onNormalMode() {
    this->currentStats->attack = this->defaultStats->attack;
}

void Character::onTurnEnded() {
}

CharacterStats *Character::getCurrentStats() {
    return currentStats;
}

void Character::removeState(int state) {
    this->state &= ~state;
}


#endif //CHARACTER_H
