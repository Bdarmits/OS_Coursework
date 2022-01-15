#ifndef PROJECT_WINDOW_H
#define PROJECT_WINDOW_H

#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <iostream>
#include <cstdlib>

class MyWindow {
public:
    Display *display;
    Window window;
    GC gc;
    void init(const char *title);
};

#endif //PROJECT_WINDOW_H
