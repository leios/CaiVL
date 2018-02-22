/*------------cairo_vis.h-----------------------------------------------------//
*
* Purpose: to visualize 2d simulation data for simuleios
*
*-----------------------------------------------------------------------------*/

#ifndef FRAME_FX_VIS
#define FRAME_FX_VIS

#include <iostream>
#include <iomanip>
#include <cairo.h>
#include <sstream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include "vec.h"

#define num_frames 1000

// Struct for colors
struct color{
    double r, g, b, a;
};

struct layer{
    int res_x, res_y;
    int line_width;
    cairo_surface_t *frame_surface;
    cairo_t *frame_ctx;
    //vec origin;
    color bg_clr;

    // Function to initialize the frame struct
    void init();

    // Simple constructor
    layer() : bg_clr(color{0,0,0,1}), res_x(600), res_y(400), line_width(3){
        init();
    };

    layer(const color& bg, int x, int y, int width) :
        bg_clr(bg), res_x(x), res_y(y), line_width(width){
        init();
    }

    // Function to destroy all contexts and surfaces
    void destroy();

};

struct frame{
    std::vector<layer> layers;
    void draw_layers();
    void clear_layers();

    void add_layer(){
        layers.emplace_back(color{0,0,0,0},layers[0].res_x,layers[0].res_y,3);
    }

    int ID = 0;
    std::string pngbase = "/tmp/image";

    // Constructors
    frame(){
        layers.emplace_back(layer());
    };
    frame(const color& bg, int x, int y, int width){
        layers.emplace_back(bg, x, y, width);
    }
};

// Function to create basic colored background
void create_bg(layer &anim, double r, double g, double b);
void create_bg(layer &anim, double r, double g, double b, double a);

// Creating basic colored background
void color_bg(layer &anim, int start_layer, int r, int g, int b);

// Function to clear a context
void clear_ctx(cairo_t* ctx);

#endif
