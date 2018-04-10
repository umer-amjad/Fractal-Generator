//
//  Point.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include "Point.hpp"

Point::Point(double x, double y): x(x), y(y) {}

void Point::translate(Point t){
    x += t.x;
    y += t.y;
}

void Point::scale(double scale, Point ref){
    Point origin = {0, 0};
    x *= scale;
    y *= scale;
    if (ref != origin){
        ref.scale(1-scale);
        this->translate(ref);
    }
}

void Point::rotate(double deg){
    short old_x = this->x;
    x = x*cos(deg*degreesToRadians) - y*sin(deg*degreesToRadians);
    y = old_x*sin(deg*degreesToRadians) + y*cos(deg*degreesToRadians);
}

Pixel Point::getPixel(GraphProperties& gp) const{
    short pixelX = round(this->x * gp.x_scale + gp.x_zero);
    short pixelY = round(-(gp.y_scale * this->y) + gp.y_zero);
    return {pixelX, pixelY};
}


bool Point::operator==(const Point &other) const {
    return (x == other.x && y == other.y);
}

bool Point::operator!=(const Point &other) const {
    return !operator==(other);
}
