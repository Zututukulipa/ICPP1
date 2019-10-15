//
// Created by Zututukulipa on 11/10/2019.
//

#include "Monster.h"

int Monster::getHp() const {
    return hp;
}

void Monster::setHp(int hp) {
    Monster::hp = hp;
}

int Monster::getMaxhp() const {
    return maxhp;
}

void Monster::setMaxhp(int maxhp) {
    Monster::maxhp = maxhp;
}
