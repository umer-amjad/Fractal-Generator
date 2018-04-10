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


class XDisplayer: public Displayer {
    Display* dis;
    Window win;
    GC gc;
    int screen;
    Colormap cmap;
public:
    XDisplayer();
    virtual void DrawLines(std::vector<Pixel>& pixels, Colour colour) override;
    ~XDisplayer();
};

#endif /* XDisplayer_hpp */
