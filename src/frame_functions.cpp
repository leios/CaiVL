#include "../include/frame_functions.h"

// Function to initialize the frame struct
void layer::init(){
    frame_surface = 
        cairo_image_surface_create(CAIRO_FORMAT_ARGB32, res_x, res_y);
    frame_ctx = cairo_create(frame_surface);
    //cairo_set_line_cap(frame_ctx, CAIRO_LINE_CAP_ROUND);
    cairo_set_line_width(frame_ctx, line_width);
    cairo_set_font_size(frame_ctx, 50.0);
    cairo_set_line_join(frame_ctx, CAIRO_LINE_JOIN_BEVEL); 
    cairo_set_line_cap(frame_ctx, CAIRO_LINE_CAP_ROUND);

    cairo_set_source_rgba(frame_ctx, bg_clr.r, bg_clr.g, 
                          bg_clr.b, bg_clr.a);
    cairo_rectangle(frame_ctx,0,0,res_x,res_y);
    cairo_fill(frame_ctx);
}

// Creating a function to destroy all contexts
void layer::destroy(){
    cairo_destroy(frame_ctx);
    cairo_surface_destroy(frame_surface);
}

// Creating basic colored background
void create_bg(layer &anim, double r, double g, double b){
    create_bg(anim, r, g, b, 1);
}
void create_bg(layer &anim, double r, double g, double b, double a){
    cairo_set_source_rgba(anim.frame_ctx, r, g, b, a);
    cairo_rectangle(anim.frame_ctx,0,0,anim.res_x,anim.res_y);
    cairo_fill(anim.frame_ctx);
}

// Creating basic colored background
void color_bg(layer &anim, int start_layer, int r, int g, int b){
    cairo_set_source_rgb(anim.frame_ctx,(double)r, (double)g, (double)b);
    cairo_rectangle(anim.frame_ctx,0,0,anim.res_x,anim.res_y);
    cairo_fill(anim.frame_ctx);
}

// Function to draw all layers
void frame::draw_layers(){
    std::string pngid, number;
    for (size_t j = 1; j < layers.size(); ++j){
        cairo_set_source_surface(layers[0].frame_ctx, 
                                 layers[j].frame_surface, 0, 0);
        cairo_paint(layers[0].frame_ctx);
    }

    // Setting up number with stringstream
    std::stringstream ss;
    ss << std::setw(5) << std::setfill('0') << ID;
    number = ss.str();

    pngid = pngbase + number + ".png";
    //std::cout << pngid << '\n';
    cairo_surface_write_to_png(layers[0].frame_surface, pngid.c_str());

    ID += 1;

    clear_layers();

}

// Function to clear a context -- BETA
void clear_ctx(cairo_t* ctx){
    // Set surface to translucent color (r, g, b, a)
    cairo_set_source_rgba (ctx, 0, 0, 0, 0);
    cairo_set_operator (ctx, CAIRO_OPERATOR_SOURCE);
    cairo_paint (ctx);
}

// Function to clear all layers
void frame::clear_layers(){

    color alpha_color = {0,0,0,0};
    cairo_save(layers[0].frame_ctx);
    cairo_set_source_rgba (layers[0].frame_ctx, 
                           layers[0].bg_clr.r, layers[0].bg_clr.g, 
                           layers[0].bg_clr.b, layers[0].bg_clr.a);
    cairo_set_operator (layers[0].frame_ctx, CAIRO_OPERATOR_SOURCE);
    cairo_paint (layers[0].frame_ctx);
    cairo_restore(layers[0].frame_ctx);

    for (int i = 1; i < layers.size(); ++i){
        cairo_save (layers[i].frame_ctx);
        cairo_set_source_rgba (layers[i].frame_ctx, 0,0,0,0);
        cairo_set_operator (layers[i].frame_ctx, CAIRO_OPERATOR_SOURCE);
        cairo_paint (layers[i].frame_ctx);
        cairo_restore(layers[i].frame_ctx);
    }
}

void camera::draw_circle(circle c){
    vec cir_loc = c.loc - loc;
    double pixel_res = image.layers[0].res_x / size.x;
    int cir_x = cir_loc.x*pixel_res + 0.5*image.layers[0].res_x;
    int cir_y = cir_loc.y*pixel_res + 0.5*image.layers[0].res_y;

    cairo_set_source_rgba(image.layers[0].frame_ctx, c.color.x, c.color.y, 
                          c.color.z, 1);
    cairo_arc(image.layers[0].frame_ctx, cir_x, cir_y, c.radius*pixel_res, 
              0, 2*M_PI);
    cairo_stroke(image.layers[0].frame_ctx);

}
