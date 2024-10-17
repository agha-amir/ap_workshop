#include "Circle.h"
#include <iostream>

Circle::Circle(float r):radius(r), Pi(3.14159265358979f){}
Circle::~Circle() {}
float Circle::perimeter() const {
    return Pi * 2 * radius;
}

float Circle::area() const {
    return Pi * radius * radius;
}



