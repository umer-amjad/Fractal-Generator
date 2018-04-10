//
//  Point.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <cmath>

const double degreesToRadians = M_PI / 180;

struct GraphProperties {
    double x_zero;
    double y_zero;
    double x_scale;
    double y_scale;
};

struct Pixel {
    short x, y;
}; //conversion from Point to Pixel

class Point{
    double x;
    double y;
    
public:
    Point(double x, double y);
    void translate(Point t);
    void scale(double scale, Point ref = {0, 0});
    void rotate(double deg);
    
    Pixel getPixel(GraphProperties& gp) const;
    
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif /* Point_hpp */
