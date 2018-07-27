//
//  FractalDrawer.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include "FractalDrawer.hpp"

#include <algorithm>

FractalDrawer::FractalDrawer(Polygon& shape, ShapeTransformer& transform, Displayer& displayer, int depth, int depthToDraw): transform(transform), displayer(displayer), depthToDraw(depthToDraw) {
    drawFractal(shape, depth);
}

FractalDrawer::FractalDrawer(std::vector<Polygon> shapes, ShapeTransformer& transform, Displayer& displayer, int depth, int depthToDraw): transform(transform), displayer(displayer), depthToDraw(depthToDraw) {
    drawFractalVector(shapes, depth);
}

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.getX() - b.getX(), 2) +
                pow(a.getY() - b.getY(), 2));
}

void FractalDrawer::drawFractal(Polygon& shape, int depth) {
    if (depth == 0) {
        return;
    }
    double maxSoFar = 0;
    const std::vector<Point>& points = shape.getPoints();
    for (int i = 0; i < points.size() - 1; ++i){
        double dist = distance(points[i], points[i+1]);
        if (dist > maxSoFar){
            maxSoFar = dist;
        }
    }
    if (maxSoFar < minLength){
        displayer.drawLines(points);
        return;
    }
    if (depth <= depthToDraw) {
        displayer.drawLines(points);
    }
    std::vector<Polygon> transformedShapes = transform(shape);

    drawFractalVector(transformedShapes, --depth);
}
void FractalDrawer::drawFractalVector(std::vector<Polygon>& shapes, int depth) {
    std::for_each(shapes.begin(), shapes.end(),
                  [&] (Polygon& shape) {
                      drawFractal(shape, depth);
                  });
}
