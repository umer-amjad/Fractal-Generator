//
//  Polygon.cpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <algorithm>

#include "Polygon.hpp"


Polygon::Polygon(std::vector<Point> points): points(points) {}

int Polygon::size(){
    return (int)points.size();
}

void Polygon::translate(Point t){
    std::for_each(points.begin(), points.end(),
                  [&t](Point& p){
                      p.translate(t);
                  });
}

void Polygon::scale(double scale, Point ref){
    std::for_each(points.begin(), points.end(),
                  [scale, &ref](Point& p){
                      p.scale(scale, ref);
                  });
}

void Polygon::rotate(double deg){
    std::for_each(points.begin(), points.end(),
                  [deg](Point& p){
                      p.rotate(deg);
                  });
}

std::vector<Pixel> Polygon::getPixels(double x_scale, double y_scale, double x_zero, double y_zero) const{
    std::vector<Pixel> pixelPoints;
    std::for_each(points.begin(), points.end(),
                  [&](const Point& p){
                      pixelPoints.push_back(p.getPixel(x_scale, y_scale, x_zero, y_zero));
                  });
    pixelPoints.push_back(pixelPoints[0]); //close the polygon
    return pixelPoints;
}

const Point& Polygon::operator[](int index) const {
    return points[index];
}



