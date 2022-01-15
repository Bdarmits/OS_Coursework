#include "../include/MyDialog.h"

void MyDialog::init(const char *title, int in_x, int in_y, int Width, int Height){
//    The initiation function of dialog window
    xd = in_x;
    yd = in_y;
    width = Width;
    height = Height;
    std::vector<MyWidget> w;
    widgets = w;
    int ScreenNumber;
    wi.display = XOpenDisplay(NULL);
    if (wi.display == NULL) {exit(1);}

    // take number of root screen
    ScreenNumber = DefaultScreen (wi.display);

    // create window
    wi.window = XCreateSimpleWindow(wi.display,
                                 RootWindow (wi.display, ScreenNumber),
                                 xd, yd, width, height, 50,
                                 BlackPixel (wi.display, ScreenNumber),
                                 WhitePixel (wi.display, ScreenNumber));

    // select events, which should be handled
    // ExposureMask means handling Exposure event
    // KeyPressMask - pressure of any key
    XSelectInput(wi.display, wi.window, ExposureMask | KeyPressMask);

    // set title for the text box
    XStoreName(wi.display, wi.window, title);

    // create graphical context
    wi.gc = XCreateGC(wi.display, wi.window, 0, NULL);

    XMapWindow(wi.display, wi.window);
    XMoveWindow(wi.display,wi.window, xd, yd);
};

void MyDialog::draw(){};

void MyDialog::expose(){
    for (auto widget : widgets){widget.expose();}
};

void MyDialog::add_widget(MyWidget widget){
    widgets.push_back(widget);
    // here you can somehow check possible events for that widget and add them to vector of events of MyDialog
};