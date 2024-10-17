#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle
{
private:
    float side1;
    float side2;
    float side3;
public:
    Triangle();
    Triangle(float, float, float);
    ~Triangle();

    float perimeter() const;
    bool isTriangle() const;

};

#endif