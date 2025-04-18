#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle
{
private:
    int Shape;
    int width_;
    int height_;
    /* data */
public:

    Rectangle(int x, int y, int w, int h);
    virtual ~Rectangle() { };
    // Circle(const Circle& ) {/*memberwise copy*/}
    // Circle& operator=(const Circle&) { /*memberwise copy*/ return this;}

    double area() const;
    double getDiagonal() const;
};

