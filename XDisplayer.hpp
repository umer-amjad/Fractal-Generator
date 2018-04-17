//
//  XDisplayer.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef XDisplayer_hpp
#define XDisplayer_hpp

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "Displayer.hpp"
#include "Point.hpp"

struct GraphProperties {
    int width;
    int height;
    double x_zero;
    double y_zero;
    double x_scale;
    double y_scale;
};

class XDisplayer: public Displayer {
    Display* dis;
    Window win;
    GC gc;
    int screen;
    GraphProperties gp;
    
    XPoint pointToPixel(const Point& p) const;
    std::vector<XPoint> pointsToPixels(const std::vector<Point>& points) const;
public:
    XDisplayer(GraphProperties gp, Colour c);
    virtual void drawLines(const std::vector<Point>& points) override;
    ~XDisplayer();
};

#endif /* XDisplayer_hpp */
