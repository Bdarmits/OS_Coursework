#include "../include/SSbutton.h"

button_clicked_state_t SSbutton::is_button_clicked(const XButtonEvent *xbutton) {
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

XImage* SSbutton::create_ximage(Display *display, Visual *visual, Window window){

    XWindowAttributes attr = {};
    XGetWindowAttributes(display, window, &attr);

    auto widthimg = attr.width;
    auto heightimg = attr.height;

    return XGetImage(display, window, 0, 0, widthimg, heightimg, AllPlanes, ZPixmap);
};

void SSbutton::spam_menu(MyDialog dialog) {
    if ((*this).activ_radio == 1 and (*this).is_active == 0){
        (*this).is_active = 1;
        dialogddl.init("", 200, 200, 1920, 1080);//
        XSelectInput(dialogddl.wi.display, dialogddl.wi.window, KeyPressMask | KeyReleaseMask | ExposureMask);
        XEvent report1;
        Visual *visual;
        XImage *ximage;
        Window root;
        visual = DefaultVisual(dialog.wi.display, 0);
        root = RootWindow(dialog.wi.display, DefaultScreen(dialog.wi.display));
        ximage = (*this).create_ximage(dialog.wi.display, visual, root);
        while (1){
            XNextEvent(dialogddl.wi.display, &report1);

            if (report1.type == Expose ){
                dialogddl.wi.gc = XCreateGC(dialogddl.wi.display, dialogddl.wi.window, 0, NULL);
                XSetForeground(dialogddl.wi.display, dialogddl.wi.gc, BlackPixel (dialogddl.wi.display, 0));

                XPutImage(dialogddl.wi.display, dialogddl.wi.window,
                          dialogddl.wi.gc, ximage, 0, 0, 0, 0,
                          1920, 1080);

                XFreeGC(dialogddl.wi.display, dialogddl.wi.gc);
                XFlush(dialogddl.wi.display);
            }
            if (report1.type == KeyPress  ) {
                if (report1.xkey.keycode == 0x09) {
                    break;
                }
            } else if(report1.type == KeyRelease){
                if (report1.xkey.keycode == 0x09) {
                    break;
                }
            }
        }
        XCloseDisplay(dialogddl.wi.display);

    }
};

void SSbutton::draw() {
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

