#include "Object.h"

Object::Object(int id):id(id){
	this->x = 0;
	this->y = 0;
}

Object::~Object() {

}

Object::Object()
{
	id = 0;
	x = 12;
	y = 12;
}

Object::Object(int id, double x, double y)
{
	this->id = id;
	this->x = x;
	this->y = y;
}

double Object::getX() const {
    return x;
}

void Object::setX(double x) {
    Object::x = x;
}

double Object::getY() const {
    return y;
}

void Object::setY(double y) {
    Object::y = y;
}

int Object::getId() const {
    return id;
}
