//
//  ShapeTransformer.hpp
//  Fractal-Generator
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef ShapeTransformer_hpp
#define ShapeTransformer_hpp

#include "Polygon.hpp"

//Abstract functor to overload to use in fractal generation

class ShapeTransformer {
public:
    virtual std::vector<Polygon> operator()(const Polygon& seed) = 0;
    
    ~ShapeTransformer(){};
};

#endif /* ShapeTransformer_hpp */
