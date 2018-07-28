//
//  Polygon.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#include <vector>
#include "Lines.hpp"

class Polygon : public Lines {    
public:
    Polygon(std::vector<Point> point);
    
    //returns a regular n-gon, centered at Center
    //where each vertex is length len away from Center
    static Polygon ngon(int n, double len, const Point center = {0, 0}){
        Point top{0, len};
        std::vector<Point> points;
        double polygonAngle = 360.0 / n; 
        for (int i = 0; i < n; ++i){
            points.push_back(top);
            top.rotate(polygonAngle);
        }
        return Polygon(points);
    }
    
    const std::vector<Point> getPoints() const override;
};

#endif /* Polygon_hpp */
