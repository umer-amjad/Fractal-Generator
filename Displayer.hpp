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

//typedef XPoint Pixel;

struct Pixel {
    short x, y;
};

class Displayer {
public:
    virtual void DrawLines(std::vector<Pixel>& pixels, Colour colour) = 0;
    virtual ~Displayer(){};
};

#endif /* Displayer_hpp */
