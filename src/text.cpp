#include "../include/text.h"
#include <string>

void Text::init(window_info wi , const char * in_text, int x_in=1100, int y_in=1100, unsigned int Width=300, unsigned int Height=100, std::string def_font_size = "16") {
//    The initiation function of button
    display = wi.display;
    window = wi.window;
    gc = wi.gc;
    x = x_in;
    y = y_in;
    width = Width;
    height = Height;
    text = in_text;
    font_size = def_font_size;
};

void Text::draw() {
//    Function for drawing the text on the window
//    ability to change cypher
    std::string st = "-sony-*-*-*-normal-*--*-*-*-*-*-*-*";
    st.insert(21, font_size);
    Font font;
    font = XLoadFont(display, st.c_str());
    XSetFont(display, gc, font);
    XDrawString(display, window, gc, x , y,
                text, strlen(text));
};

void Text::expose() {
    draw();
};