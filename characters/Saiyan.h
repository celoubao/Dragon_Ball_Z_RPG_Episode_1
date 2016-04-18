//
// Created by cloubao on 4/7/16.
//

#ifndef SAIYAN_H
#define SAIYAN_H

#include "../components/Character.h"

class Saiyan : public Character {

public:
    Saiyan();
};

Saiyan::Saiyan() {
    resetCharacterStats();
}

#endif //SAIYAN_H
