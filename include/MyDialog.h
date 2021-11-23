#ifndef PROJECT_MYDIALOG_H
#define PROJECT_MYDIALOG_H

#include <X11/Xlib.h>
#include <stdio.h>
#include <vector>
#include "widget.h"

struct window_info{
    Display *display;
    Window window;
    GC gc;
};


class MyDialog {
public:
    window_info wi;

    //TODO: vector of possible events, for further their handling
    //std::vector<XEvent.type> events_types;

    std::vector<MyWidget> widgets;
    int x, y, width, height;

    void init(const char *title, int in_x, int in_y, int Width, int Height);

    void draw();

    void expose();

    void add_widget(MyWidget widget);



};


#endif //PROJECT_MYDIALOG_H
