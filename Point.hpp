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

class Point {
    double x;
    double y;
    
public:
    Point(double x, double y);
    void translate(Point t);
    void scale(double scale, Point ref = {0, 0});
    void rotate(double deg, Point ref = {0, 0});
    
    double getX() const;
    double getY() const;
    
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif /* Point_hpp */
