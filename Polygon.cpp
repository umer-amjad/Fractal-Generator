//
//  Polygon.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <algorithm>

#include "Polygon.hpp"


Polygon::Polygon(std::vector<Point> points): points(points) {}

void Polygon::translate(Point t){
    std::for_each(points.begin(), points.end(),
                  [&t](Point& p){
                      p.translate(t);
                  });
}

void Polygon::scale(double scale, Point ref){
    std::for_each(points.begin(), points.end(),
                  [scale, &ref](Point& p){
                      p.scale(scale, ref);
                  });
}

void Polygon::rotate(double deg){
    std::for_each(points.begin(), points.end(),
                  [deg](Point& p){
                      p.rotate(deg);
                  });
}


