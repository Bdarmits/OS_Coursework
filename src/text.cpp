#include "../include/text.h"
#include "../include/MyDialog.h"
#include <string>


void Text::init(window_info wi , const char * in_text, int x_in=X, int y_in=Y, unsigned int Width=WIDTH, unsigned int Height=HEIGHT, std::string def_font_size = "16") {
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

//    XFontStruct* txtsize;
    std::string st = "-sony-*-*-*-normal-*--*-*-*-*-*-*-*";
    st.insert(21, font_size);
    Font font;
    font = XLoadFont(display, st.c_str());
//    gc = XCreateGC(display,window,0,NULL);
    XSetFont(display, gc, font);
//    XTextExtents(txtsize, text, strlen(text), FontLeftToRight, ascent ,height, );
    XDrawString(display, window, gc, x , y,
                text, strlen(text));
};


void Text::expose() {
    draw();
};