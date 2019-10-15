//
// Created by Zututukulipa on 11/10/2019.
//

#ifndef SESSION03_INDIVIDUAL_WORK_MONSTER_H
#define SESSION03_INDIVIDUAL_WORK_MONSTER_H


#include "MovingObject.h"

class Monster: MovingObject {
int hp;
int maxhp;
public:
    int getHp() const;

    void setHp(int hp);

    int getMaxhp() const;

    void setMaxhp(int maxhp);
};


#endif //SESSION03_INDIVIDUAL_WORK_MONSTER_H
