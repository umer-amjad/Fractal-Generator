//
//  main.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <iostream>
#include <vector>

#include "Polygon.hpp"
#include "XDisplayer.hpp"

int main(int argc, char* argv[]){
    double x_zero = 500;
    double y_zero = 400;
    double x_scale = 1;
    double y_scale = 1;
    XDisplayer xd;
    Polygon square({{256, 256}, {-256, 256}, {-256, -256}, {256, -256}});
    for (int i = 0; i < 120; ++i){
        Colour c{0, short(255 - i), short(135 + i)};
        //XSetForeground(dis,gc,45568+i*5);//changes colour throughout
        std::vector<Pixel> squarePixels = square.getPixels(x_scale, y_scale, x_zero, y_zero);
        xd.DrawLines(squarePixels, c);
        Point firstPoint = square[0];
        square.scale(0.97, firstPoint);
        square.rotate(3);
        square.translate({-1, -1});
    }
    int x;
    std::cin >> x;
}
