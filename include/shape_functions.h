/*------------shape_functions.h-----------------------------------------------//
*
* Purpose: to draw shapes of varying types in CaiVL
*
*-----------------------------------------------------------------------------*/

#ifndef SHAPE_FX_VIS
#define SHAPE_FX_VIS

#include "vec.h"
#include "string"

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

struct textbox{
    vec loc;
    vec color;
    double font_size = 1;
    int justification = 0;
    std::string text;

    textbox(const std::string t, const vec l, const vec c) :
            text(t), loc(l), color(c){};
    textbox(const std::string t, const vec l, const vec c, double fs) :
            text(t), loc(l), color(c), font_size(fs){};
    textbox(const std::string t, const vec l, const vec c, double fs, int j) :
            text(t), loc(l), color(c), font_size(fs), justification(j){};
};

#endif
