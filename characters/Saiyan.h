//
// Created by Charles-Eugene Loubao on 4/7/16.
//

#ifndef SAIYAN_H
#define SAIYAN_H

#include "../components/Character.h"

class Saiyan : public Character {

public:
    Saiyan();
};

Saiyan::Saiyan() {
    setMaxKI(KI_BAR * 4);
    resetCharacterStats();
}

#endif //SAIYAN_H
