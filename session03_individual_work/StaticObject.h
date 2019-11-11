#ifndef SESSION03_INDIVIDUAL_WORK_STATICOBJECT_H
#define SESSION03_INDIVIDUAL_WORK_STATICOBJECT_H


#include "Object.h"

enum class ObstacleType {
    rock, small_plant, big_plant
};

class StaticObject : public Object {
private:
    ObstacleType obstacleType;
public:
	StaticObject(int id, ObstacleType typeOfObstacle);
	~StaticObject();
	ObstacleType getObstacleType() const;
};


#endif //SESSION03_INDIVIDUAL_WORK_STATICOBJECT_H
