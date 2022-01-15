#include "../include/TextInputField.h"

button_clicked_state_t TextInputField::is_button_clicked(const XButtonEvent *xbutton) {
//    A function for tracking if field was pressed
    if (xbutton->button != Button1)
        return BTN_IGNORE_CLICK;
    if (mouseover) {
        clicked = xbutton->type == ButtonPress ? 1 : 0;
        if (!clicked) {
            activ_radio = activ_radio == 0 ? 1 : 0;
            return BTN_IS_CLICKED;
        }
        return BTN_OTHER1;
    } else {
        clicked = 0;
        return BTN_OTHER2;
    }
};

void TextInputField::add_text(XEvent report){
//    A function for displaying
    if(report.xkey.keycode == 0x16 ) {
        (*this).nickname = (*this).nickname.substr(0, (*this).nickname.size() - 1);
        (*this).expose();
    } else if ((*this).nickname.size() <= 11 && report.xkey.keycode != 0x09){
        KeySym sym1 = XLookupKeysym(&report.xkey, 0);
        (*this).nickname += XKeysymToString(sym1);
        (*this).expose();
        printf( "KeyPress: %s\n", XKeysymToString(sym1) );
    }
};
//
//void TextInputField::remove_text() {
//};

void TextInputField::draw() {
    XClearArea(display, window, x, y, width + 40, height, False);

    // change color of the button if mouse is over the button
    text = nickname.c_str();

    XSetForeground(display, gc, fg);
    XSetBackground(display, gc, bg);
    XDrawRectangle(display, window, gc, x, y, width + 40, height);

    // text coordinates relatively to button size
    int textx, texty;
    textx = x + 5;
    texty = y + height - 3;

//    // draw text inside button
    XDrawString(display, window, gc, clicked + textx, clicked + texty,
                text, strlen(text));

    XSetForeground(display, gc, fg);
    XSetBackground(display, gc, bg);
};
