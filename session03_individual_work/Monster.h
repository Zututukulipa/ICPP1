#ifndef SESSION03_INDIVIDUAL_WORK_MONSTER_H
#define SESSION03_INDIVIDUAL_WORK_MONSTER_H


#include "MovingObject.h"

class Monster : public MovingObject {
private:
	int hp;
	int maxhp;
public:

	Monster();
	Monster(int hp, int maxhp);
	Monster(int hp, int maxhp, double azimut, int id, int x, int y);
	~Monster();
	int getHp() const;

	void setHp(int hp);

	int getMaxhp() const;

	void setMaxhp(int maxhp);
};


#endif //SESSION03_INDIVIDUAL_WORK_MONSTER_H
