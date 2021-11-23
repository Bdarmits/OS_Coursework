#ifndef PROJECT_WIDGET_H
#define PROJECT_WIDGET_H


#define WIDTH 300
#define HEIGHT 100

#include <X11/Xlib.h>
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

    void expose();

    void remove();


};

#endif //PROJECT_WIDGET_H
