//
//  Polygon.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <algorithm>

#include "Polygon.hpp"

Polygon::Polygon(std::vector<Point> points): Lines(points) {}

const std::vector<Point> Polygon::getPoints() const {
    std::vector<Point> copy = points;
    copy.push_back(copy[0]); //loop around to first point
    return copy;
}