#include "Monster.h"

Monster::Monster():MovingObject()
{
	hp = 50;
	maxhp = 100;
}

Monster::Monster(int hp, int maxhp)
{
	this->hp = hp;
	this->maxhp = maxhp;
}

Monster::Monster(int hp, int maxhp, double azimut, int id, int x, int y):MovingObject(azimut,id, x,y)
{
	this->hp = hp;
	this->maxhp = maxhp;
}

Monster::~Monster()
{
}

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
