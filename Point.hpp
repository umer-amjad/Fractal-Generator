//
//  Point.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <cmath>
#include <X11/Xlib.h>


const double degreesToRadians = M_PI / 180;

class Point{
    double x;
    double y;
    
public:
    Point(double x, double y);
    void translate(Point t);
    void scale(double scale, Point ref = {0, 0});
    void rotate(double deg);
    
    XPoint getPixel(double x_scale, double y_scale, double x_zero, double y_zero) const;
    
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif /* Point_hpp */
