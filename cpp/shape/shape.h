#ifndef SHAPE_H
#define SHAPE_H

class Shape
{           //Abstract Base Class(ABC)
// private:
   protected:
    int x_;
    int y_;
    
public:
    Shape();
    Shape(int x, int y);
    // Shape(const Shape& ) {/*memberwise copy*/};
    virtual ~Shape() {};
    // Shape& operator=(const Shape& ) { /*memberwise copy */ return *this;}

    void move(int x, int y);
    virtual double area() const = 0;            //can't be implemented. -->pure virtual func(가상함수)

};

#endif