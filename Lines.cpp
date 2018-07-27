// Lines.cpp

#include <algorithm>

#include "Lines.hpp"

Lines::Lines(std::vector<Point> points): points(points) {}

void Lines::translate(Point t) {
    std::for_each(points.begin(), points.end(),
                  [&t] (Point& p) {
                      p.translate(t);
                  });
}

void Lines::scale(double scale, Point ref) {
    std::for_each(points.begin(), points.end(),
                  [scale, &ref] (Point& p) {
                      p.scale(scale, ref);
                  });
}

void Lines::rotate(double deg, Point ref) {
    std::for_each(points.begin(), points.end(),
                  [deg, &ref] (Point& p) {
                      p.rotate(deg, ref);
                  });
}

const std::vector<Point> Lines::getPoints() const {
    return points;
}

std::vector<Point>::const_iterator Lines::begin() const {
    return points.begin();
}
std::vector<Point>::const_iterator Lines::end() const {
    return points.end();
}

int Lines::size() const {
    return (int) points.size();
}

const Point& Lines::operator[](int index) const {
    return points[index];
}


