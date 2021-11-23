#include "../include/MyDialog.h"


void MyDialog::init(const char *title, int in_x, int in_y, int Width, int Height){
    x = in_x;
    y = in_y;
    width = Width;
    height = Height;
    std::vector<MyWidget> w;
    widgets = w;

    int ScreenNumber;

    wi.display = XOpenDisplay(NULL);
    if (wi.display == NULL) {
        exit(1);
    }

    // take number of root screen
    ScreenNumber = DefaultScreen (wi.display);

    int blackColor = BlackPixel(wi.display, ScreenNumber);
    int whiteColor = WhitePixel(wi.display, ScreenNumber);

    // create window
    wi.window = XCreateSimpleWindow(wi.display,
                                 RootWindow (wi.display, ScreenNumber),
                                 x, y, width, height, BORDER_WIDTH,
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
};

void MyDialog::draw(){

};

void MyDialog::expose(){
    for (auto widget : widgets){
        widget.expose();
    }
};

void MyDialog::add_widget(MyWidget widget){
    widgets.push_back(widget);
    // here you can somehow check possible events for that widget and add them to vector of events of MyDialog
};