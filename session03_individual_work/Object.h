#ifndef SESSION03_INDIVIDUAL_WORK_OBJECT_H
#define SESSION03_INDIVIDUAL_WORK_OBJECT_H


class Object {
    int id;
    double x;
    double y;
public:
    int getId() const;

	Object();
	Object(int id, double x, double y);
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    virtual ~Object();

    Object(int id);
};


#endif //SESSION03_INDIVIDUAL_WORK_OBJECT_H
