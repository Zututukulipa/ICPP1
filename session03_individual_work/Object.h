//
// Created by Zututukulipa on 11/10/2019.
//

#ifndef SESSION03_INDIVIDUAL_WORK_OBJECT_H
#define SESSION03_INDIVIDUAL_WORK_OBJECT_H


class Object {
    int id;
    double x;
    double y;
public:
    int getId() const;

public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

public:
    virtual ~Object();

public:
    Object(int id);
};


#endif //SESSION03_INDIVIDUAL_WORK_OBJECT_H
