//
//  Polygon.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <algorithm>

#include "Polygon.hpp"


Polygon::Polygon(std::vector<Point> points): points(points) {}

void Polygon::rotate(double deg){
    std::for_each(points.begin(), points.end(),
                  [deg](Point& p){
                      p.rotate(deg);
                  });
}

void Polygon::scaleOrigin(double scale){
    std::for_each(points.begin(), points.end(),
                  [scale](Point& p){
                      p.scale(scale);
                  });
}

void Polygon::translate(Point t){
    std::for_each(points.begin(), points.end(),
                  [&t](Point& p){
                      p.translate(t);
                  });
}
