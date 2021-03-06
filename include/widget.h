#ifndef PROJECT_WIDGET_H
#define PROJECT_WIDGET_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include "window.h"

class MyWidget {
public:
    Display *display;
    Window window;
    GC gc;
    int x;
    int y;
    unsigned int width;
    unsigned int height;

    void init(MyWindow window1, int x_in, int y_in, unsigned int Width, unsigned int Height);
    virtual void expose();
    void remove();
};

#endif //PROJECT_WIDGET_H
