//
// Created by Zututukulipa on 11/10/2019.
//

#include "Object.h"

Object::Object(int id) : id(id) {}

Object::~Object() {

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
