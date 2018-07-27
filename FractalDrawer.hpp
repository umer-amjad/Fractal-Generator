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
    // (can turn off stopAtMinLength in FractalDrawer constructor
    double minLength = 5;
    int depthToDraw; //optional, default (1) draws last iteration, 2 means last two iterations, etc    
public:
    //two constructors, one for single shape and one for vector of shapes
    FractalDrawer(Polygon& shape, ShapeTransformer& transform, Displayer& displayer, int depth, int depthToDraw = 1);
    FractalDrawer(std::vector<Polygon> shapes, ShapeTransformer& transform, Displayer& displayer, int depth, int depthToDraw = 1);
    
    void drawFractal(Polygon& shape, int depth);
    void drawFractalVector(std::vector<Polygon>& shapes, int depth);
};
#endif /* FractalDrawer_hpp */
