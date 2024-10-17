#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle{
private:

float width;
float height;

public:
    Rectangle();
    Rectangle(float, float);
    ~Rectangle();
    void changeWidth(float);
    void changeHeight(float);
    float area() const;
    float perimeter() const;
};
#endif
