#include "Game.h"
#include "Monster.h"
#include "StaticObject.h"
#include <iostream>
#define AMOUNT 15
int main() {
	Game* g = new Game();
	for (int i = 0; i < AMOUNT; i++)
	{
		if (i % 2 == 0)
			g->addObject(new Monster(300,300,150,1,12,24));
		else {
			g->addObject(new StaticObject(1, ObstacleType::big_plant));
		}
	}

	
	auto neco = g->findMovingObjectsInArea(0, 0, 2000);
	


	delete g;

	return 0;
}