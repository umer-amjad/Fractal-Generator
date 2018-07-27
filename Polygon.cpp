//
//  Polygon.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <algorithm>

#include "Polygon.hpp"

Polygon::Polygon(std::vector<Point> points): points(points) {}

void Polygon::translate(Point t) {
    std::for_each(points.begin(), points.end(),
                  [&t] (Point& p) {
                      p.translate(t);
                  });
}

void Polygon::scale(double scale, Point ref) {
    std::for_each(points.begin(), points.end(),
                  [scale, &ref] (Point& p) {
                      p.scale(scale, ref);
                  });
}

void Polygon::rotate(double deg, Point ref) {
    std::for_each(points.begin(), points.end(),
                  [deg, &ref] (Point& p) {
                      p.rotate(deg, ref);
                  });
}

const std::vector<Point> Polygon::getPoints() const {
    std::vector<Point> copy = points;
    copy.push_back(copy[0]); //loop around to first point
    return copy;
}

std::vector<Point>::const_iterator Polygon::begin() const {
    return points.begin();
}
std::vector<Point>::const_iterator Polygon::end() const {
    return points.end();
}

int Polygon::size() const {
    return (int) points.size();
}

const Point& Polygon::operator[](int index) const {
    return points[index];
}



