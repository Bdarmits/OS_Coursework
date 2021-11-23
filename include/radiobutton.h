#ifndef PROJECT_RADIOBUTTON_H
#define PROJECT_RADIOBUTTON_H


#include "widget.h"

class RadioButton : public MyWidget    {
public:
    int clicked;
    XFontStruct* font;
    const char *text;

    void init(MyWindow window1, int x, int y, const char *text);

    void draw();

    void expose();
    //TODO: add any helper functions if needed


};


#endif //PROJECT_RADIOBUTTON_H
