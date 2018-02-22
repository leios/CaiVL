/*-------------vis_test.cpp---------------------------------------------------//
* 
* Purpose: To test visualizing our cairo animations
*
*-----------------------------------------------------------------------------*/

#include "../include/cairo_vis.h"
#include "../include/frame_functions.h"

int main(){

    color bg = {0, 0, 0, 1};
    frame test(bg, 600, 400, 1);
    test.add_layer();
    cairo_set_source_rgba(test.layers[1].frame_ctx, 1, 1, 0, 1);
    cairo_arc(test.layers[1].frame_ctx, 200, 150, 50, 0, M_PI);
    cairo_stroke(test.layers[1].frame_ctx);
    test.draw_layers();
    test.draw_layers();

/*
    vec res = {400, 300};
    int fps = 30;
    color bg_clr = {0.5,0,0.5,1};
    std::vector<frame> layers = init_layers(3, res, fps, bg_clr);

    cairo_set_source_rgba(layers[1].frame_ctx, 0, 1, 0, 1);
    cairo_arc(layers[1].frame_ctx, 200, 150, 50, 0, M_PI);
    cairo_stroke(layers[1].frame_ctx);
    draw_layers(layers);
    clear_layers(layers, bg_clr);

    cairo_set_source_rgba(layers[1].frame_ctx, 1, 1, 0, 1);
    cairo_set_line_width(layers[1].frame_ctx, 2);
    cairo_arc(layers[1].frame_ctx, 200, 150, 50, 0, 2*M_PI);
    cairo_stroke(layers[1].frame_ctx);
    draw_layers(layers);
*/

/*
    // Initialize visualization stuff
    vec res = {400, 300};
    int fps = 30;
    color bg_clr = {0,0,0,1};

    std::vector<frame> layers = init_layers(3, res, fps, bg_clr);

    // Defining color to use for lines
    color line_clr = {1, 1, 1, 1};
    color line_clr_2 = {1, 0, 1, 1};

    vec ori = {200, 150};

    //grow_circle(layers[1], 1, 100, 200, ori, 10, 1); 

    vec dim = {100, 150};
    grow_rect(layers[1], 1, 100, 200, ori, dim, line_clr);
    grow_rect(layers[1], 1, ori, dim, line_clr_2);
    grow_square(layers[1], 1, 200, 300, ori, 200, line_clr);
    grow_circle(layers[1], 1, ori, 200, line_clr_2);

    write_fraction(layers[1], ori, 1,20,100, line_clr);

    std::vector<double> temp_array(4);
    temp_array[0] = 1;
    temp_array[1] = -0.5;
    temp_array[2] = 0.5;
    temp_array[3] = 2;

    vec origin = {layers[0].res_x*0.5,layers[0].res_y*0.5,0};
    vec dimension = {150,100,0};

    color white = {1, 1, 1, 1};
    color grey = {0.5, 0.5, 0.5, 1};

    plot(layers[1], temp_array, 1, 0, 100, origin, dimension, grey, white);

    draw_layers(layers);
*/
}
