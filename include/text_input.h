#ifndef PROJECT_TEXT_INPUT_H
#define PROJECT_TEXT_INPUT_H


#include "widget.h"

class TextInput : public MyWidget {
public:
    //TODO: if you need, also add 'width' and 'height' attributes for sizes of text input box
    const char * text;

    void init(MyWindow window1, int x, int y);

    void draw();

    void expose();
    //TODO: add any helper functions if needed
};


#endif //PROJECT_TEXT_INPUT_H
