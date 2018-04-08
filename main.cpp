//
//  main.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <iostream>
#include <vector>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "Polygon.hpp"

void display() {
    Display *dis;
    int screen;
    Window win;
    GC gc;
    /* get the colors black and white (see section for details) */
    unsigned long black,white;
    
    /* use the information from the environment variable DISPLAY
     to create the X connection:
     */
    dis = XOpenDisplay("");
    screen = DefaultScreen(dis);
    black = BlackPixel(dis,screen);    /* get color black */
    white = WhitePixel(dis, screen);  /* get color white */
    
    /* once the display is initialized, create the window.
     This window will be have be 200 pixels across and 300 down.
     It will have the foreground white and background black
     */
    
    int height = 800;
    int width = 1000;
    
    double x_zero = 500;
    double y_zero = 400;
    double x_scale = 1;
    double y_scale = 1;
    
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
    
    /* here is another routine to set the foreground and background
     colors _currently_ in use in the window.
     */
    for(;;) {
        XEvent e;
        XNextEvent(dis, &e);
        if (e.type == MapNotify)
            break;
    }
    
    XSetForeground(dis,gc,black);
    
    //draw x axis:
    //XDrawLine(dis, win, gc, 0, y_zero, width-1, y_zero);
    
    //draw y axis:
    //XDrawLine(dis, win, gc, x_zero, 0, x_zero, height-1);
    
    XSetForeground(dis,gc,45568);//green
    
    //draw graph
    Polygon square({{256, 256}, {-256, 256}, {-256, -256}, {256, -256}});
    for (int i = 0; i < 85; ++i){
        //XSetForeground(dis,gc,45568+i*5);//changes colour throughout
        XDrawLines(dis, win, gc, square.getPixels(x_scale, y_scale, x_zero, y_zero), (int)square.size() + 1, CoordModeOrigin);
        Point firstPoint = square[0];
        square.scale(0.95, firstPoint);
        square.rotate(3);
        square.translate({-1, -5});
    }
    
    XFlush(dis);
};

int main(int argc, char* argv[]){
    display();
    int x;
    std::cin >> x;
}
