#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle(int x, int y, int w, int h)
: Shape(x,y), width_(W), height_(h)
{


}

double Rectangle::area() const
{
    return width_ *height_;
}

double Rectangle::getDiagonal()
{
    return  Math.sqrt(Math.pow(x,2)+Math.pow(y,2));
}
