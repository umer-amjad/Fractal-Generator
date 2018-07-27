//
//  Polygon.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#include <vector>
#include "Lines.hpp"

class Polygon : public Lines {    
public:
    Polygon(std::vector<Point> point);
    
    const std::vector<Point> getPoints() const override;
};

#endif /* Polygon_hpp */
