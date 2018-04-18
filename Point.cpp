//
//  Point.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include "Point.hpp"

Point::Point(double x, double y): x(x), y(y) {}

void Point::translate(Point t) {
    x += t.x;
    y += t.y;
}

void Point::scale(double scale, Point ref) {
    Point origin = {0, 0};
    x *= scale;
    y *= scale;
    if (ref != origin) {
        ref.scale(1-scale);
        this->translate(ref);
    }
}

void Point::rotate(double deg, Point ref) {
    short old_x = this->x;
    x = (x - ref.x)*cos(deg*degreesToRadians) - (y - ref.y)*sin(deg*degreesToRadians);
    y = (old_x - ref.x)*sin(deg*degreesToRadians) + (y - ref.y)*cos(deg*degreesToRadians);
    x += ref.x;
    y += ref.y;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}


bool Point::operator==(const Point &other) const {
    return (x == other.x && y == other.y);
}

bool Point::operator!=(const Point &other) const {
    return !operator==(other);
}
