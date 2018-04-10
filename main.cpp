//
//  main.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>

#include "ShapeTransformer.hpp"
#include "XDisplayer.hpp"
#include "FractalDrawer.hpp"

class SquareTest1: public ShapeTransformer{
    virtual std::vector<Polygon> operator()(const Polygon& seed) override {
        std::vector<Polygon> transformed;
        Polygon copy = seed;
        Point firstPoint = copy[0];
        copy.scale(0.97, firstPoint);
        copy.rotate(3);
        copy.translate({-1, -1});
        return {copy};
    }
};

class SquareTest2: public ShapeTransformer{
    virtual std::vector<Polygon> operator()(const Polygon& seed) override {
        std::vector<Polygon> transformed;
        Polygon copy = seed;
        Point firstPoint = copy[0];
        Point thirdPoint = copy[2];
        copy.scale(0.5, firstPoint);
        copy.rotate(25);
        transformed.push_back(copy);
        Polygon copy2 = seed;
        copy2.scale(0.5, thirdPoint);
        copy2.rotate(25);
        transformed.push_back(copy2);
        return transformed;
    }
};

class SerpinskiTransformer: public ShapeTransformer{
    double scalar = 0.5; //default
public:
    SerpinskiTransformer(){};
    SerpinskiTransformer(double scalar): scalar(scalar){};

    virtual std::vector<Polygon> operator()(const Polygon& seed) override {
        std::vector<Polygon> transformed;
        for (auto& vertex: seed){
            Polygon copy = seed;
            copy.scale(scalar, vertex);
            transformed.push_back(copy);
        }
        return transformed;
    }
};

int main(int argc, char* argv[]){
    GraphProperties gp{500, 400, 1, 1};
    XDisplayer xd;
    Displayer& displayer = xd;
    Polygon square({{256, 256}, {-256, 256}, {-256, -256}, {256, -256}});
    Point initial({0, 400});
    std::vector<Point> forTriangle;
    forTriangle.push_back(initial);
    initial.rotate(120);
    forTriangle.push_back(initial);
    initial.rotate(120);
    forTriangle.push_back(initial);
    Polygon triangle(forTriangle);
    
    std::vector<Point> forHexagon;
    for (int i = 0; i < 6; i++){
        initial.rotate(60);
        forHexagon.push_back(initial);
    }
    Polygon hexagon(forHexagon);
    
    Point initial2{0, 400};
    std::vector<Point> forOctagon;
    for (int i = 0; i < 8; i++){
        initial2.rotate(45);
        forOctagon.push_back(initial2);
    }
    Polygon octagon(forOctagon);
    
    Colour col{0, 255, 135};
    SerpinskiTransformer testTransform(0.29);
    FractalDrawer(octagon, testTransform, 4, displayer, gp, col);
    
//    for (int i = 0; i < 120; ++i){
//        Colour c{0, short(255 - i), short(135 + i)};
//        //XSetForeground(dis,gc,45568+i*5);//changes colour throughout
//        std::vector<Pixel> squarePixels = square.getPixels(gp);
//        displayer.DrawLines(squarePixels, c);
//        Point firstPoint = square[0];
//        square.scale(0.97, firstPoint);
//        square.rotate(3);
//        square.translate({-1, -1});
//    }
    int x;
    std::cin >> x;
}
