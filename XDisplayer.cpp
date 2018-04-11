//
//  XDisplayer.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <algorithm>

#include "XDisplayer.hpp"
#include "Point.hpp"

XDisplayer::XDisplayer(){
    dis = XOpenDisplay("");
    screen = DefaultScreen(dis);
    unsigned long white = WhitePixel(dis, screen);  /* get color white */
    
    /* once the display is initialized, create the window.
     It will have background white
     */
    
    int height = 800;
    int width = 1000;
    
    win = XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,
                              width, height, 5, white, white);
    
    
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
    cmap = DefaultColormap(dis, screen);

    
    /* here is another routine to set the foreground and background
     colors _currently_ in use in the window.
     */
    for(;;) {
        XEvent e;
        XNextEvent(dis, &e);
        if (e.type == MapNotify)
            break;
    }
    
    //draw x axis:
    //XDrawLine(dis, win, gc, 0, y_zero, width-1, y_zero);
    
    //draw y axis:
    //XDrawLine(dis, win, gc, x_zero, 0, x_zero, height-1);
    
    //XSetForeground(dis,gc,45568);//green
}

void XDisplayer::DrawLines(std::vector<Pixel> &pixels, Colour colour){
    std::vector<XPoint> xpointPixels;
    std::for_each(pixels.begin(), pixels.end(),
                  [&xpointPixels](const Pixel& p){
                      XPoint xp{p.x, p.y};
                      xpointPixels.push_back(xp);
                  });
    XColor xcolor;
    xcolor.red = colour.red * 256;
    xcolor.green = colour.green * 256;
    xcolor.blue = colour.blue * 256;
    //xcolor.flags = DoRed | DoGreen | DoBlue;
    //XAllocColor(dis, cmap, &xcolor); //for fast testing
    XSetForeground(dis, gc, 65415);
    XDrawLines(dis, win, gc, xpointPixels.data(), (int)pixels.size(), CoordModeOrigin);
    XFlush(dis);
}

XDisplayer::~XDisplayer(){
    XFreeGC(dis, gc);
    XDestroyWindow(dis,win);
    XCloseDisplay(dis);
}
