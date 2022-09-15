//
//  FractalDrawer.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include "FractalDrawer.hpp"

#include <algorithm>

FractalDrawer::FractalDrawer(Polygon& shape, ShapeTransformer& transform, 
    Displayer& displayer, double minLength, bool lastValid, int depth, int depthToDraw): 
    transform(transform), displayer(displayer), minLength(minLength), onlyDrawLastValid(lastValid), depthToDraw(depthToDraw), initialDepth(depth) {
    if (onlyDrawLastValid && minLength > 1){
        depth = INT_MAX;
    }
    drawFractal(shape, depth);
}

FractalDrawer::FractalDrawer(std::vector<Polygon> shapes, 
    ShapeTransformer& transform, Displayer& displayer, double minLength, bool lastValid, int depth, int depthToDraw): 
    transform(transform), displayer(displayer), minLength(minLength), onlyDrawLastValid(lastValid), depthToDraw(depthToDraw) {
    if (onlyDrawLastValid && minLength > 1){
        depth = INT_MAX;
    }
    drawFractalVector(shapes, depth);
}

double FractalDrawer::distance(const Point& a, const Point& b) {
    return sqrt(pow(displayer.getXScale()*(a.getX() - b.getX()), 2) +
                pow(displayer.getYScale()*(a.getY() - b.getY()), 2));
}

bool FractalDrawer::validLength(const std::vector<Point>& points) {
    double maxSoFar = 0;
    for (int i = 0; i < points.size() - 1; ++i){
        double dist = distance(points[i], points[i+1]);
        if (dist > maxSoFar){
            maxSoFar = dist;
        }
    }
    return maxSoFar >= minLength;
}

void FractalDrawer::drawFractal(Polygon& shape, int depth) {
    if (depth == 0) {
        if (onlyDrawLastValid) {
            displayer.drawLines(shape.getPoints());
        }
        return;
    }
    const std::vector<Point>& points = shape.getPoints();

    if (onlyDrawLastValid && !validLength(points)){
        displayer.drawLines(points);
        return;
    }
    if ((!onlyDrawLastValid && depthToDraw == -1) || (initialDepth - depth >= depthToDraw && depthToDraw != -1)) {
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
