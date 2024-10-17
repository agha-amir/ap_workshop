#include <stdio.h>
#include <iostream>
#include "Triangle.h"


Triangle::Triangle():side1(0), side2(0), side3(0){}

Triangle::Triangle(float s1, float s2, float s3):side1(s1), side2(s2), side3(s3){
}

float Triangle::perimeter() const{
    return side1 + side2 + side3;
}

bool Triangle::isTriangle() const{
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1){return true;}
    return false;
}

Triangle::~Triangle(){
    
}


