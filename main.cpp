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
        return {copy};
    }
};

class SquareTest2: public ShapeTransformer {
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

double serpinskiScaleFactor(int dim) {
    int quarter_dim = dim / 4;
    double accumulator = 0;
    for (int k = 1; k <= quarter_dim; ++k) {
        accumulator += cos((2.0 * M_PI * k) / dim);
    }
    return 1.0/(2.0 * (1.0 + accumulator));
}

class SerpinskiTransform: public ShapeTransformer {
    double scalar = -1; //default
public:
    SerpinskiTransform() {};
    SerpinskiTransform(double scalar): scalar(scalar) {};

    virtual std::vector<Polygon> operator()(const Polygon& seed) override {
        if (scalar == -1) {
            scalar = serpinskiScaleFactor(seed.size());
        }
        std::vector<Polygon> transformed;
        for (auto& vertex: seed) {
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
        for (auto& vertex: seed) {
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

int main(int argc, char* argv[]) {
    // width, height, x_zero, y_zero, x_scale, y_scale
    GraphProperties gp{1200, 750, 600, 300, 1, 1};
    Colour col{0, 255, 200}; // my favourite colour
    XDisplayer xd(gp, col);
    
    std::vector<Point> forDragon;
    Point top{0, -200};
    forDragon.push_back(top);
    top.rotate(90, {0, 100});
    forDragon.push_back(top);
    top.rotate(180, {0, 100});
    forDragon.push_back(top);
    Polygon dragon(forDragon);
    
    DragonTransform transform1;
    SerpinskiTransform transform2;
    // shape(polygon), transform, displayer, minLength, lastValid, depth, depthoDraw
    FractalDrawer(dragon, transform1, xd, 1, true, 15);
    Polygon testgon = Polygon::ngon(3, 300);
    for (int i = 1; i < 8; ++i) {
        XDisplayer xd2(gp, col);
        FractalDrawer(testgon, transform2, xd2, 1, false, i);
        std::cout << "Press Enter to continue" << std::endl;
        std::cin.get();
    }

    SquareTest1 transform3;
    Polygon square = Polygon::ngon(4, 300);
    XDisplayer xd3(gp, col);
    for (int i = 100; i >= 0; i-= 10) {
        FractalDrawer(square, transform3, xd3, 0, false, 100, i);
        std::cout << "Press Enter to continue" << std::endl;
        std::cin.get();
    }
    
    //stop program from exiting:
    std::cout << "Press Enter to exit and close windows" << std::endl;
    std::cin.get();
}
