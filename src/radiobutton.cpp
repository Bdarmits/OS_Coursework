#include "../include/radiobutton.h"

button_clicked_state_t RadioButton::is_button_clicked(const XButtonEvent *xbutton) {
//    A function for tracking if radio button was pressed
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

void RadioButton::draw() {
//    Function for drawing the radiobutton on the window
    XClearArea(display, window, x, y, width, height, False);
    int textrbx, textrby;
    textrbx = x + 5;
    textrby = y + height - 15;

    // change color of the button if mouse is over the button
    if (activ_radio == 1) {
        XSetForeground(display, gc, fg);
        XSetBackground(display, gc, bg);
        XDrawRectangle(display, window, gc, x, y, width, height);
        XFillArc(display,window,gc, textrbx, textrby, 11, 11, 0, 23040);
        XDrawArc(display,window, gc, textrbx, textrby, 11, 11, 0, 23040);

    } else {
        XSetForeground(display, gc, fg);
        XSetBackground(display, gc, bg);
        XDrawRectangle(display, window, gc, x, y, width, height);
        XDrawArc(display,window, gc, textrbx, textrby, 11, 11, 0, 23040);
    }

    // text coordinates relatively to button size
    int textx, texty;
    textx = x + 20;
    texty = y + height - 3;
    // draw text inside button
    XDrawString(display, window, gc, clicked + textx, clicked + texty,
                text, strlen(text));
    XSetForeground(display, gc, fg);
    XSetBackground(display, gc, bg);
};

