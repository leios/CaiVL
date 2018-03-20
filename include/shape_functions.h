/*------------shape_functions.h-----------------------------------------------//
*
* Purpose: to darw shapes of varying types in CaiVL
*
*-----------------------------------------------------------------------------*/

#ifndef SHAPE_FX_VIS
#define SHAPE_FX_VIS

#include "vec.h"

struct circle{
    vec loc;
    double radius;
    vec color;
 
    circle(const vec l, const double r, const vec c) : 
           loc(l), radius(r), color(c){};
};

#endif
