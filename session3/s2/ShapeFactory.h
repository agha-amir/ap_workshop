#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
class ShapeFactory{
private:
    static int triangleNum;
    static int circleNum;
    static int rectangleNum;
    //static int limit = 100;

    static Circle** circleArr;
    static Triangle** triangleArr;
    static Rectangle** rectangleArr;

    ShapeFactory();
    ~ShapeFactory();
public:

    static Triangle* buildTriangle(float, float, float );
    static Circle* buildCircle(float);
    static Rectangle* buildRectangle(float, float);
    static int triangleCount();
    static int rectangleCount();
    static int circleCount();
    static void deleteShapes();
};
#endif
