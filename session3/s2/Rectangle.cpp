#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle():height(0), width(0){}

Rectangle::Rectangle(float h, float w) :width(w), height(h){}

Rectangle::~Rectangle(){}

void Rectangle::changeHeight(float h) {
    height = h;
}

void Rectangle::changeWidth(float w) {
    width = w;
}

float Rectangle::area() const{
    return height * width;
}

float Rectangle::perimeter() const{
    return (height + width) * 2;
}

