#ifndef PROJECT_TEXT_H
#define PROJECT_TEXT_H


#include "widget.h"
#include "window.h"
#include "MyDialog.h"


class Text : public MyWidget {
public:

    const char* text;
    std::string font_size;

    void init(window_info wi, const char * in_text, int x_in, int y_in, unsigned int Width, unsigned int Height, std::string def_font_size);

    void draw();

    void expose();


};


#endif //PROJECT_TEXT_H
