//
//  Point.hpp
//  Fractal-Generator
//
//  Created by H263353 on 4/7/18.
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <cmath>

const double degreesToRadians = M_PI / 180;

class Point{
public:
    double x;
    double y;
    
    Point(double x, double y);
    void rotate(double deg);
    void scale(double scale);
    void translate(double x_translate, double y_translate);
    
};

#endif /* Point_hpp */
