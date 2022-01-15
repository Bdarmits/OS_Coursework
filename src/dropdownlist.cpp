#include "../include/dropdownlist.h"

button_clicked_state_t Dropdownlist::is_button_clicked(const XButtonEvent *xbutton) {
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
void Dropdownlist::destroy_menu() {
    XCloseDisplay(dialogddl.wi.display);
};
void Dropdownlist::spam_menu() {
    if ((*this).activ_radio == 1 and (*this).is_active == 0){
        (*this).is_active = 1;
        dialogddl.init("", 200 + 35, 200 + 90 + (*this).height * 3 , (*this).width, (*this).height + 100 );//
        XEvent report1;
        XNextEvent(dialogddl.wi.display, &report1);
        Button buttonrd1;
        buttonrd1.init(dialogddl.wi, 0, 0, "Options");
        buttonrd1.draw();
        if (report1.type == Expose ){
            dialogddl.wi.gc = XCreateGC(dialogddl.wi.display, dialogddl.wi.window, 0, NULL);
            XSetForeground(dialogddl.wi.display, dialogddl.wi.gc, BlackPixel (dialogddl.wi.display, 0));

            buttonrd1.expose();

            XFreeGC(dialogddl.wi.display, dialogddl.wi.gc);
            XFlush(dialogddl.wi.display);
        }

    }
};

void Dropdownlist::draw() {
    XClearArea(display, window, x, y, width, height, False);

    XSetForeground(display, gc, fg);
    XSetBackground(display, gc, bg);
    XDrawRectangle(display, window, gc, x, y, width, height);

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


