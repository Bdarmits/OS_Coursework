#include "../include/window.h"


void MyWindow::init(const  char *title="Example") {
    int ScreenNumber;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        exit(1);
    }

    // take number of root screen
    ScreenNumber = DefaultScreen (display);

    int blackColor = BlackPixel(display, ScreenNumber);
    int whiteColor = WhitePixel(display, ScreenNumber);

    // create window
    window = XCreateSimpleWindow(display,
                                 RootWindow (display, ScreenNumber),
                                 X, Y, WIDTH, HEIGHT, BORDER_WIDTH,
                                 BlackPixel (display, ScreenNumber),
                                 WhitePixel (display, ScreenNumber));


    // select events, which should be handled
    // ExposureMask means handling Exposure event
    // KeyPressMask - pressure of any key
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // set title for the text box
    XStoreName(display, window, title);

    // create graphical context
    gc = XCreateGC(display, window, 0, NULL);

    XMapWindow(display, window);

};