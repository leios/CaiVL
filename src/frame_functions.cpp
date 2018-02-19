#include "../include/frame_functions.h"

// Function to initialize the frame struct
void frame::init(){
    int line_width = 3;
    for (size_t i = 0; i < num_frames; ++i){
        frame_surface[i] = 
            cairo_image_surface_create(CAIRO_FORMAT_ARGB32, res_x, res_y);
        frame_ctx[i] = cairo_create(frame_surface[i]);
        //cairo_set_line_cap(frame_ctx[i], CAIRO_LINE_CAP_ROUND);
        cairo_set_line_width(frame_ctx[i], line_width);
        cairo_set_font_size(frame_ctx[i], 50.0);
        cairo_set_line_join(frame_ctx[i], CAIRO_LINE_JOIN_BEVEL); 
        cairo_set_line_cap(frame_ctx[i], CAIRO_LINE_CAP_ROUND);
    }
    bg_surface = 
        cairo_image_surface_create(CAIRO_FORMAT_ARGB32, res_x, res_y);
    bg_ctx = cairo_create(bg_surface);
    curr_frame = 0;
}

// Creating a function to destroy all contexts
void frame::destroy_all(){
    for (int i = 0; i < num_frames; i++){
        cairo_destroy(frame_ctx[i]);
        cairo_surface_destroy(frame_surface[i]);
    }
    cairo_destroy(bg_ctx);
    cairo_surface_destroy(bg_surface);
}

// Creating basic colored background
void create_bg(frame &anim, double r, double g, double b){
    create_bg(anim, r, g, b, 1);
}
void create_bg(frame &anim, double r, double g, double b, double a){
    for (int i = 0; i < num_frames; ++i){
        cairo_set_source_rgba(anim.frame_ctx[i], r, g, b, a);
        cairo_rectangle(anim.frame_ctx[i],0,0,anim.res_x,anim.res_y);
        cairo_fill(anim.frame_ctx[i]);
    }
}

// Creating basic colored background
void color_bg(frame &anim, int start_layer, int r, int g, int b){
    for (int i = start_layer; i < num_frames; ++i){
        cairo_set_source_rgb(anim.frame_ctx[i],(double)r, (double)g, (double)b);
        cairo_rectangle(anim.frame_ctx[i],0,0,anim.res_x,anim.res_y);
        cairo_fill(anim.frame_ctx[i]);
    }
}

// Function to draw all frames in the frame struct
void frame::draw_frames(){
    std::string pngid, number;
    for (size_t i = 0; i < num_frames; ++i){
        cairo_set_source_surface(frame_ctx[i], frame_surface[i], 0, 0);
        cairo_paint(frame_ctx[i]);

        // Setting up number with stringstream
        std::stringstream ss;
        ss << std::setw(5) << std::setfill('0') << i;
        number = ss.str();

        pngid = pngbase + number + ".png";
        std::cout << pngid << '\n';
        cairo_surface_write_to_png(frame_surface[i], pngid.c_str());
    }

}

// Function to set the initial variables
void frame::create_frame(int x, int y, int ps, std::string pngname){
    res_x = x;
    res_y = y;
    pngbase = pngname;
    fps = ps;
    origin.x = (double)x / 2.0;
    origin.y = (double)y / 2.0;
}

// Function to draw all layers
void draw_layers(std::vector<frame> &layer){
    std::string pngid, number;
    for (size_t i = 0; i < num_frames; ++i){
        for (size_t j = 1; j < layer.size(); ++j){
            cairo_set_source_surface(layer[0].frame_ctx[i], 
                                     layer[j].frame_surface[i], 0, 0);
            cairo_paint(layer[0].frame_ctx[i]);
        }

        // Setting up number with stringstream
        std::stringstream ss;
        ss << std::setw(5) << std::setfill('0') << i;
        number = ss.str();

        pngid = layer[0].pngbase + number + ".png";
        //std::cout << pngid << '\n';
        cairo_surface_write_to_png(layer[0].frame_surface[i], pngid.c_str());
    }

}

// Function to clear a context -- BETA
void clear_ctx(cairo_t* ctx){
    // Set surface to translucent color (r, g, b, a)
    cairo_save (ctx);
    cairo_set_source_rgba (ctx, 0, 0, 0, 0);
    cairo_set_operator (ctx, CAIRO_OPERATOR_SOURCE);
    cairo_paint (ctx);
    cairo_restore (ctx);
}

std::vector<frame> init_layers(int layer_num, vec res, int fps, color bg_clr){
    std::vector<frame> layers(layer_num);
    for (size_t i = 0; i < layers.size(); i++){
        layers[i].create_frame(res.x, res.y,fps,"/tmp/image");
        layers[i].init();
        layers[i].curr_frame = 1;
    }
    create_bg(layers[0], bg_clr.r, bg_clr.g, bg_clr.b, bg_clr.a);

    return layers;
}
