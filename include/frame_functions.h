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

struct frame{
    int res_x, res_y;
    int fps;
    int curr_frame;
    cairo_surface_t *frame_surface[num_frames];
    cairo_t *frame_ctx[num_frames];
    cairo_surface_t *bg_surface;
    cairo_t *bg_ctx;
    vec origin;
    std::string pngbase;

    // Function to call frame struct
    void create_frame(int x, int y, int ps, std::string pngname);

    // Function to initialize the frame struct
    void init();

    // Function to draw all frames in the frame struct
    void draw_frames();

    // Function to destroy all contexts and surfaces
    void destroy_all();

};

// Function to create basic colored background
void create_bg(frame &anim, double r, double g, double b);
void create_bg(frame &anim, double r, double g, double b, double a);

// Creating basic colored background
void color_bg(frame &anim, int start_layer, int r, int g, int b);

// Function to draw layers
void draw_layers(std::vector<frame> &layer);

// Function to clear a context
void clear_ctx(cairo_t* ctx);

// Function to initialize a vector of frames (layers)
std::vector<frame> init_layers(int layer_num, vec res, int fps, color bg_clr);

#endif
