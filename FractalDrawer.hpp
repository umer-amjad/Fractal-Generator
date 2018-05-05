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
    int depthToDraw; //optional, default always draws, 1 means last iteration, 2 means last two iterations
    
public:
    //two constructors, one for single shape and one for vector of shapes
    FractalDrawer(Polygon& shape, ShapeTransformer& transform, int depth, Displayer& displayer, int depthToDraw = INT_MAX);
    FractalDrawer(std::vector<Polygon> shapes, ShapeTransformer& transform, int depth, Displayer& displayer, int depthToDraw = INT_MAX);
    
    void drawFractal(Polygon& shape, int depth);
    void drawFractalVector(std::vector<Polygon> shapes, int depth);
};
#endif /* FractalDrawer_hpp */
