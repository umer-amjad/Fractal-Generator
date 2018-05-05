//
//  XDisplayer.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <algorithm>
#include <iostream> //debug

#include "XDisplayer.hpp"

XPoint XDisplayer::pointToPixel(const Point& p) const {
    short pixelX = round(p.getX() * gp.x_scale + gp.x_zero);
    short pixelY = round(-(gp.y_scale * p.getY()) + gp.y_zero);
    return {pixelX, pixelY};
}

std::vector<XPoint> XDisplayer::pointsToPixels(const std::vector<Point>& points) const {
    std::vector<XPoint> pixels;
    std::for_each(points.begin(), points.end(),
                  [&] (const Point& p) {
                      pixels.push_back(pointToPixel(p));
                  });
    return pixels;
}

XDisplayer::XDisplayer(GraphProperties gp, Colour c) : gp(gp) {
    std::cout << "Point 1" << std::endl;
    dis = XOpenDisplay((char *)0);
    std::cout << "Point 2" << std::endl;
    screen = DefaultScreen(dis);
    std::cout << "Point 2.5" << std::endl;
    unsigned long white = WhitePixel(dis, screen);  /* get color white */
    std::cout << "Point 2.6" << std::endl;
    /* once the display is initialized, create the window.
     It will have background white
     */
    
    int height = gp.height;
    int width = gp.width;
    std::cout << "Point 3" << std::endl;
    win = XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,
                              width, height, 5, white, white);
    std::cout << "Point 4" << std::endl;
    
    /* here is where some properties of the window can be set.
     The third and fourth items indicate the name which appears
     at the top of the window and the name of the minimized window
     respectively.
     */
    XSetStandardProperties(dis,win,"Test Fractal","Test",None,NULL,0,NULL);
    
    XSelectInput(dis, win, StructureNotifyMask);
    
    XMapWindow(dis, win);
    
    /* create the Graphics Context */
    gc = XCreateGC(dis, win, 0,0);
    
    /* create colour map */
    Colormap cmap = DefaultColormap(dis, screen);
    XColor xcolor;
    xcolor.red = c.red * 256;
    xcolor.green = c.green * 256;
    xcolor.blue = c.blue * 256;
    xcolor.flags = DoRed | DoGreen | DoBlue;
    XAllocColor(dis, cmap, &xcolor); //allocate colour
    XSetForeground(dis, gc, xcolor.pixel); //set colour

    
    /* here is another routine to set the foreground and background
     colors _currently_ in use in the window.
     */
    for(;;) {
        XEvent e;
        XNextEvent(dis, &e);
        if (e.type == MapNotify)
            break;
    }
    std::cout << "Point 5" << std::endl;
    //draw x axis:
    //XDrawLine(dis, win, gc, 0, y_zero, width-1, y_zero);
    
    //draw y axis:
    //XDrawLine(dis, win, gc, x_zero, 0, x_zero, height-1);
    
    //XSetForeground(dis,gc,45568);//green
}

void XDisplayer::drawLines(const std::vector<Point>& points) {
    std::vector<XPoint> xpointPixels = pointsToPixels(points);

    XDrawLines(dis, win, gc, xpointPixels.data(), (int)xpointPixels.size(), CoordModeOrigin);
    XFlush(dis);
}

XDisplayer::~XDisplayer() {
    XFreeGC(dis, gc);
    XDestroyWindow(dis,win);
    XCloseDisplay(dis);
}
