#include "../include/widget.h"


void MyWidget::init(MyWindow window1, int x_in, int y_in, unsigned int Width=WIDTH, unsigned int Height=HEIGHT) {
    display = window1.display;
    window = window1.window;
    gc = window1.gc;

    x = x_in;
    y = y_in;
    width = Width;
    height = Height;

};

void MyWidget::expose() {
    std::cout<<"Here"<<std::endl;
};

//TODO: implement remove
void MyWidget::remove() {};

