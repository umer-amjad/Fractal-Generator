//
//  Polygon.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#include <vector>

#include "Point.hpp"

class Polygon{
    std::vector<Point> points;
    
public:
    Polygon(std::vector<Point> point);
    void rotate(double deg);
    void scaleOrigin(double scale);
    void scalePoint(Point ref, double scale);
    void translate(Point t);
};

#endif /* Polygon_hpp */
