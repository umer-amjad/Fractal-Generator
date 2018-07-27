#ifndef LINES_H
#define LINES_H

#include <vector>
#include "Point.hpp"


class Lines {
    std::vector<Point> points;
    
public:
    Lines(std::vector<Point> point);
    
    virtual void translate(Point t);
    virtual void scale(double scale, Point ref = {0, 0});
    virtual void rotate(double deg, Point ref = {0, 0});
    
    virtual const std::vector<Point> getPoints() const;
    
    virtual std::vector<Point>::const_iterator begin() const;
    virtual std::vector<Point>::const_iterator end() const;
    virtual int size() const;
    virtual const Point& operator[](int index) const;
};

#endif /* LINES_H */

