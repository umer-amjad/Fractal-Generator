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

class FractalDrawer {
    ShapeTransformer& transform;
    Displayer& displayer;
    GraphProperties& gp;
    Colour& col;
public:
    //two constructors, one for single shape and one for vector of shapes
    FractalDrawer(Polygon& shape, ShapeTransformer& transform, int depth, Displayer& displayer, GraphProperties& gp, Colour& col);
    FractalDrawer(std::vector<Polygon> shapes, ShapeTransformer& transform, int depth, Displayer& displayer, GraphProperties& gp, Colour& col);
    
    void drawFractal(Polygon& shape, int depth);
    void drawFractalVector(std::vector<Polygon> shapes, int depth);
};
#endif /* FractalDrawer_hpp */
