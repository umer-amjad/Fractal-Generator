//
//  Displayer.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Displayer_hpp
#define Displayer_hpp

#include <vector>

//Abstract class for drawing objects:
struct Colour {
    short red, green, blue;
};

class Point;


class Displayer {
protected:
public:
    virtual void drawLines(const std::vector<Point>& points) = 0;
    virtual void clear() = 0;
    virtual void setScales(double x, double y) = 0;
    virtual double getXScale() const = 0;
    virtual double getYScale() const = 0;
    virtual ~Displayer() {};
};

#endif /* Displayer_hpp */
