#ifndef PROJECT_RADIOBUTTON_H
#define PROJECT_RADIOBUTTON_H


#include "widget.h"
#include "button.h"

class RadioButton : public Button    {
public:
    int activ_radio = 0;
//    int clicked;
//    XFontStruct* font;
//    const char *text;
//    int rd_x;
//    int rd_y;
//    int state;

//    void init(window_info window1, int x, int y, const char *in_text);
    button_clicked_state_t is_button_clicked(const XButtonEvent* xbutton ) override;
    void draw() override;


};


#endif //PROJECT_RADIOBUTTON_H
