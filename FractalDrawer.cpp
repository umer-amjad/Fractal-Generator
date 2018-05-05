//
//  FractalDrawer.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include "FractalDrawer.hpp"

#include <algorithm>

FractalDrawer::FractalDrawer(Polygon& shape, ShapeTransformer& transform, int depth, Displayer& displayer, int depthToDraw): transform(transform), displayer(displayer), depthToDraw(depthToDraw) {
    drawFractal(shape, depth);
}

FractalDrawer::FractalDrawer(std::vector<Polygon> shapes, ShapeTransformer& transform, int depth, Displayer& displayer, int depthToDraw): transform(transform), displayer(displayer), depthToDraw(depthToDraw) {
    drawFractalVector(shapes, depth);
}

void FractalDrawer::drawFractal(Polygon& shape, int depth) {
    if (depth == 0) {
        return;
    }
    if (depth <= depthToDraw) {
        displayer.drawLines(shape.getPoints());
    }
    std::vector<Polygon> transformedShapes = transform(shape);

    drawFractalVector(transformedShapes, --depth);
}
void FractalDrawer::drawFractalVector(std::vector<Polygon> shapes, int depth) {
    std::for_each(shapes.begin(), shapes.end(),
                  [&] (Polygon& shape) {
                      drawFractal(shape, depth);
                  });
}
