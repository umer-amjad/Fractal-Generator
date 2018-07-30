//
//  FractalDrawer.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef FractalDrawer_hpp
#define FractalDrawer_hpp

#include "ShapeTransformer.hpp"
#include "Displayer.hpp"

#include <climits>

class FractalDrawer {
    ShapeTransformer& transform;
    Displayer& displayer;    
    // if length of longest line during drawLines is < minLength, drawing does not occur
    // (turned off when onlyDrawLastValid is false)
    double minLength;
    bool onlyDrawLastValid;
    int depthToDraw; //optional, set if onlyDrawLastValid is false

    
    //returns true if longest line length is >= minLength
    bool validLength(const std::vector<Point>& points);
    
    double distance(const Point& a, const Point& b);
public:
    //two constructors, one for single shape and one for vector of shapes
    FractalDrawer(Polygon& shape, ShapeTransformer& transform, Displayer& displayer, double minLength = 5, bool lastValid = true, int depth = 1, int depthToDraw = 1);
    FractalDrawer(std::vector<Polygon> shapes, ShapeTransformer& transform, Displayer& displayer, double minLength = 5, bool lastValid = true, int depth = 1, int depthToDraw = 1);
    
    void drawFractal(Polygon& shape, int depth);
    void drawFractalVector(std::vector<Polygon>& shapes, int depth);
};
#endif /* FractalDrawer_hpp */
