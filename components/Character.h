#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "../include/Terminal.h"

using namespace std;

static const int LIFE_BAR = 1000;
static const int KI_BAR = 500;

class Character {
protected:
    void setMaxHP(long maxHP);

    void setMaxKI(long maxKI);

    void setDefensePoints(float dps);

    void setName(string name);

    void setAttackPoints(float APS);


public:
    Character();

    long getActualKI();

    void setActualKI(long ki);

    long getMaxKI();

    long getActualHP();

    long getMaxHP();

    float getDefensePoints();

    float getAttackBonusPoints();

    string getName();

    void setActualHP(double hp);

    void resetCharacterStats();

private:
    string name;
    long maxHP;
    long actualHP;

    long actualKI = KI_BAR;
    long maxKI;

    float DPS;
    float ABS;
};

Character::Character() {
    setMaxHP(LIFE_BAR * 3);
    setMaxKI(KI_BAR * 3);
    resetCharacterStats();
}

void Character::setAttackPoints(float ABS) {
    this->ABS = ABS;
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

void Character::setDefensePoints(float dps) {
    this->DPS = dps;
}

string Character::getName() {
    return name;
}

long Character::getActualHP() {
    return actualHP;
}

float Character::getDefensePoints() {
    return DPS;
}

float Character::getAttackBonusPoints() {
    return ABS;
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

void Character::setActualKI(long ki) {
    if(actualKI < maxKI || ki < maxKI) {
        this->actualKI = ki;
        if(actualKI >= maxKI) {
            actualKI = maxKI;
            cout << getName() << " is in Power Max Mode!" << endl;
        }
    }
    else {
        cout << getName() << "'s KI cannot go higher!";
    }
}

void Character::setMaxKI(long maxKI) {
    this->maxKI = maxKI;
}

long Character::getMaxKI() {
    return this->maxKI;
}


#endif //CHARACTER_H
