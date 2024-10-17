#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
private:

float radius;

public:
    const float Pi;
    Circle();
    Circle(float);
    ~Circle();
    float area() const;
    float perimeter() const;
};


#endif
