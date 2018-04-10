//
//  FractalDrawer.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include "FractalDrawer.hpp"

FractalDrawer::FractalDrawer(Polygon& shape, ShapeTransformer& transform, int depth, Displayer& displayer, GraphProperties& gp, Colour& col): transform(transform), displayer(displayer), gp(gp), col(col) {
    drawFractal(shape, depth);
}

FractalDrawer::FractalDrawer(std::vector<Polygon> shapes, ShapeTransformer& transform, int depth, Displayer& displayer, GraphProperties& gp, Colour& col): transform(transform), displayer(displayer), gp(gp), col(col) {
    drawFractalVector(shapes, depth);
}

void FractalDrawer::drawFractal(Polygon& shape, int depth){
    std::vector<Pixel> pixelsToDraw = shape.getPixels(gp);
    displayer.DrawLines(pixelsToDraw, col);
    std::vector<Polygon> transformedShapes = transform(shape);
    if (depth == 0){
        return;
    }
    drawFractalVector(transformedShapes, --depth);
}
void FractalDrawer::drawFractalVector(std::vector<Polygon> shapes, int depth){
    std::for_each(shapes.begin(), shapes.end(),
                  [&](Polygon& shape){
                      drawFractal(shape, depth);
                  });
}
