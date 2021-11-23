#ifndef PROJECT_BUTTON_H
#define PROJECT_BUTTON_H

#include "widget.h"
#include "MyDialog.h"

typedef enum {BTN_IGNORE_CLICK = 0, BTN_IS_CLICKED = 1, BTN_OTHER1 = 2, BTN_OTHER2 = 3 } button_clicked_state_t;


class Button : public MyWidget{
public:
    int mouseover;
    int clicked;
    const char* text;
    XFontStruct* font;
    int fg;
    int bg;

    void init(window_info wi, int x, int y, const char * text);

    button_clicked_state_t is_button_clicked(const XButtonEvent* xbutton );
    int button_mouseover_changed(const XMotionEvent* xmotion);

    void draw();

    void expose();

private:

    int is_point_inside(int px, int py);
    void free_button();

};


#endif //PROJECT_BUTTON_H
