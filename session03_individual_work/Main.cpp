#include "Game.h"
#include "Monster.h"
#include "StaticObject.h"

int main() {
	Game* g = new Game();
	for (int i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
			g->addObject(new Monster(300,300,150,1,12,24));
		else {
			g->addObject(new StaticObject(1, ObstacleType::big_plant));
		}
	}



	delete g;

	return 0;
}