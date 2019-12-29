#include "Plumbing.h"
#include <iostream>
#include <fstream>
#include <sstream>

Plumbing::Plumbing(std::string plumbing_path)
{
	height = 0; width = 0;
	int*** a = new int** [height];

	std::string line;
	std::ifstream infile;
	infile.open(plumbing_path);

	while (std::getline(infile, line))
	{
		infile >> line;
		std::cout << line;
	}

	infile.close();
}

const APlumbingElement* Plumbing::GetElement(int x, int y) const
{
	return elementField[x][y];
}

bool Plumbing::IsPlumbingOk() const
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (!GetElement(i, j)->isCorrectlyConnected(this))
				return false;
		}
	}
	return true;
}