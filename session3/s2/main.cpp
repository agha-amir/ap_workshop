#include "ShapeFactory.h"
#include <iostream>
using namespace std;

int main(){

    Triangle* rightTriangle = ShapeFactory::buildTriangle(3.0f, 4.0f, 5.0f);
    Triangle* wrongTriangle = ShapeFactory::buildTriangle(1.5f, 2.5f, 4.0f);

    cout<<"validating triangles"<<endl;
    cout<<"triangle 1: "<<boolalpha<<rightTriangle->isTriangle()<<endl;
    cout<<"triangle 2: "<<boolalpha<<wrongTriangle->isTriangle()<<endl<<endl;

    Rectangle* rectangle1 = ShapeFactory::buildRectangle(5.5f, 5.5f);
    Rectangle* rectangle2 = ShapeFactory::buildRectangle(4.5f, 5.5f);
    Rectangle* rectangle3 = ShapeFactory::buildRectangle(6.5f, 5.5f);

    cout<<"rectangle1's area:  "<<rectangle1->area()<<endl;
    cout<<"rectangle1's perimeter:  "<<rectangle1->perimeter()<<endl;


    cout<<"rectangle2's area:  "<<rectangle2->area()<<endl;
    cout<<"rectangle2's perimeter:  "<<rectangle2->perimeter()<<endl;


    cout<<"rectangle3's area:  "<<rectangle3->area()<<endl;
    cout<<"rectangle3's perimeter:  "<<rectangle3->perimeter()<<endl<<endl;

    cout<<"changing rectangles scales...."<<endl;

    rectangle1->changeHeight(7.0f);
    rectangle1->changeWidth(8.5f);

    rectangle2->changeHeight(6.0f);
    rectangle2->changeWidth(7.5f);

    rectangle3->changeHeight(5.0f);
    rectangle3->changeWidth(6.5f);

    cout<<"rectangle1's area after change:  "<<rectangle1->area()<<endl;
    cout<<"rectangle1's perimeter after change:  "<<rectangle1->perimeter()<<endl;


    cout<<"rectangle2's area after change:  "<<rectangle2->area()<<endl;
    cout<<"rectangle2's perimeter after change:  "<<rectangle2->perimeter()<<endl;


    cout<<"rectangle3's area after change:  "<<rectangle3->area()<<endl;
    cout<<"rectangle3's perimeter after change:  "<<rectangle3->perimeter()<<endl<<endl;

    Circle* circle = ShapeFactory::buildCircle(4.5f);
    cout<<"circle's area: "<<circle->area()<<endl;
    cout<<"circle's perimeter: "<<circle->perimeter()<<endl<<endl;


    cout<<"total circle counts: "<<ShapeFactory::circleCount()<<endl;
    cout<<"total triangle counts: "<<ShapeFactory::triangleCount()<<endl;
    cout<<"total rectangle counts: "<<ShapeFactory::rectangleCount()<<endl;

    ShapeFactory::deleteShapes();


    return 0;
}
