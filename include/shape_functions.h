/*------------shape_functions.h-----------------------------------------------//
*
* Purpose: to draw shapes of varying types in CaiVL
*
*-----------------------------------------------------------------------------*/

#ifndef SHAPE_FX_VIS
#define SHAPE_FX_VIS

#include "vec.h"

struct circle{
    vec loc;
    vec color;

    double radius;
    double angle = 2*M_PI;
    double start_angle = 0;

    int draw_type = 0;
 
    circle(const vec l, const double r, const vec c) : 
           loc(l), radius(r), color(c){};
    circle(const vec l, const double r, const vec c, int dt) : 
           loc(l), radius(r), color(c), draw_type(dt){};
};

struct line{
    vec loc1, loc2, color;

    int line_width;

    line(const vec l1, const vec l2, const vec c) :
        loc1(l1), loc2(l2), color(c){};
};

#endif
