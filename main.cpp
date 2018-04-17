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
            //copy.rotate(36);
            transformed.push_back(copy);
        }
        return transformed;
    }
};

class KochTransform: public ShapeTransformer{
    virtual std::vector<Polygon> operator()(const Polygon& seed) override {
        std::vector<Polygon> transformed;
        int i = 1;
        int size = seed.size();
        for (auto& vertex: seed){
            Polygon copy = seed;
            copy.scale(1/3.0, vertex);
            copy.rotate(180, copy[i % size]);
            transformed.push_back(copy);
            ++i;
        }
        return transformed;
    }
};

class DragonTransform: public ShapeTransformer {
    virtual std::vector<Polygon> operator()(const Polygon& seed) override {
        std::vector<Polygon> transformed;
        Point midpoint = seed[1]; //start as second point
        midpoint.scale(0.5, seed[2]); //calculate average of second and third
        Polygon firstTriangle({midpoint, seed[0], seed[1]});
        transformed.push_back(firstTriangle);
        firstTriangle.rotate(90, seed[0]); //second triangle
        transformed.push_back(firstTriangle);
        return transformed;
    }
};

int main(int argc, char* argv[]){
    // width, height, x_zero, y_zero, x_scale, y_scale
    GraphProperties gp{1000, 900, 550, 400, 1, 1};
    Colour col{0, 255, 135};
    XDisplayer xd(gp, col);
    Displayer& displayer = xd;
    Polygon square({{100, 100}, {-100, 100}, {-100, -100}, {100, -100}});
    Point initial({0, 400});
    std::vector<Point> forTriangle;
    forTriangle.push_back(initial);
    initial.rotate(120);
    forTriangle.push_back(initial);
    initial.rotate(120);
    forTriangle.push_back(initial);
    Polygon triangle(forTriangle);
    
    std::vector<Point> forPentagon;
    for (int i = 0; i < 5; i++){
        initial.rotate(72);
        forPentagon.push_back(initial);
    }
    Polygon pentagon(forPentagon);
    
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
    
    std::vector<Point> forDragon;
    Point initial3{0, -200};
    forDragon.push_back(initial3);
    initial3.rotate(90, {0, 100});
    forDragon.push_back(initial3);
    initial3.rotate(180, {0, 100});
    forDragon.push_back(initial3);
    Polygon dragon(forDragon);
    
    DragonTransform testTransform;
    FractalDrawer(dragon, testTransform, 20, displayer, 1);
    
    int x;
    std::cin >> x;
}
