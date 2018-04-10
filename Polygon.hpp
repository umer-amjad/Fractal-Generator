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

class Polygon {
    std::vector<Point> points;
    
public:
    Polygon(std::vector<Point> point);
    int size();
    
    void translate(Point t);
    void scale(double scale, Point ref = {0, 0});
    void rotate(double deg);
    
    std::vector<Pixel> getPixels(GraphProperties& gp) const;
    
    std::vector<Point>::const_iterator begin() const;
    std::vector<Point>::const_iterator end() const;
    const Point& operator[](int index) const;
    
};

#endif /* Polygon_hpp */
