//
//  Point.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include "Point.hpp"

Point::Point(double x, double y): x(x), y(y) {}

void Point::rotate(double deg){
    short old_x = this->x;
    x = x*cos(deg*degreesToRadians) - y*sin(deg*degreesToRadians);
    y = old_x*sin(deg*degreesToRadians) + y*cos(deg*degreesToRadians);
}

void Point::scale(double scale, Point ref){
    x *= scale;
    y *= scale;
}

void Point::translate(Point t){
    x += t.x;
    y += t.y;
}

