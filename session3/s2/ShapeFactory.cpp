#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ShapeFactory.h"
#include <iostream>

int ShapeFactory::rectangleNum = 0;
int ShapeFactory::triangleNum = 0;
int ShapeFactory::circleNum = 0;
Circle** ShapeFactory::circleArr = new Circle*[100];
Triangle** ShapeFactory::triangleArr = new Triangle*[100];
Rectangle** ShapeFactory::rectangleArr = new Rectangle*[100];

ShapeFactory::ShapeFactory(){
}

ShapeFactory::~ShapeFactory() {}


Circle *ShapeFactory::buildCircle(float radius = 5) {
    Circle* circle = new Circle(radius);
    circleArr[circleNum] = circle;
    circleNum += 1;
    return circle;
}

Rectangle *ShapeFactory::buildRectangle(float h = 5, float w = 10) {
    Rectangle* rectangle = new Rectangle(h, w);
    rectangleArr[rectangleNum] = rectangle;
    rectangleNum ++;
    return rectangle;
}

Triangle *ShapeFactory::buildTriangle(float s1, float s2, float s3) {
    Triangle* triangle = new Triangle(s1, s2, s3);
    triangleArr[triangleNum] = triangle;
    triangleNum++;
    return triangle;
}

int ShapeFactory::triangleCount(){
    return ShapeFactory::triangleNum;
}

int ShapeFactory::rectangleCount(){
    return ShapeFactory::rectangleNum;
}

int ShapeFactory::circleCount(){
    return ShapeFactory::circleNum;
}

void ShapeFactory::deleteShapes() {
    for (int i = 0; i < circleNum; ++i) {
        delete circleArr[i];
    }

    for (int i = 0; i < triangleNum; ++i) {
        delete triangleArr[i];
    }

    for (int i = 0; i < rectangleNum; ++i) {
        delete rectangleArr[i];
    }

    delete[] circleArr;
    delete[] triangleArr;
    delete[] rectangleArr;
}

