#include "StaticObject.h"

StaticObject::StaticObject(int id, ObstacleType typeOfObstacle) : Object(id) {
	this->obstacleType = typeOfObstacle;
}

StaticObject::~StaticObject()
{
}

ObstacleType StaticObject::getObstacleType() const
{
	return  obstacleType;
}
