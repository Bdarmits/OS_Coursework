#include "../include/button.h"

int Button::is_point_inside(int px, int py) {
//    a function for tracking if mouse cursor is in the area of button
    return px >= x && px <= (x + (int) width - 1) &&
           py >= y && py <= (y + (int) height - 1);
};

int Button::button_mouseover_changed(const XMotionEvent *xmotion) {
//    Check if cursor is in the area of button and return 1/0 correspondingly
    int res = 0;
    if (is_point_inside(xmotion->x, xmotion->y)) {
        if (!mouseover)
            res = 1;
        mouseover = 1;
    } else {
        if (mouseover)
            res = 1;
        mouseover = 0;
        clicked = 0;
    }
    return res;
};

button_clicked_state_t Button::is_button_clicked(const XButtonEvent *xbutton) {
//    A function for tracking if button was pressed
    if (xbutton->button != Button1)
        return BTN_IGNORE_CLICK;

    if (mouseover) {
        clicked = xbutton->type == ButtonPress ? 1 : 0;

        if (!clicked) {
            return BTN_IS_CLICKED;
        }
        return BTN_OTHER1;
    } else {
        clicked = 0;
        return BTN_OTHER2;
    }
};

static XFontStruct *get_default_button_font(Display *display) {
//    load text font
    return XLoadQueryFont(display, "fixed");
}

void Button::init(window_info wi, int in_x, int in_y, const char *in_text) {
//    The initiation function of button
    display = wi.display;
    window = wi.window;
    gc = wi.gc;
    font = get_default_button_font(display);
    XSetFont(display, gc, font->fid);
    text = in_text;
    int direction = 0, ascent = 0, descent = 0;
    XCharStruct overall;
    XTextExtents(font, text, strlen(text), &direction, &ascent, &descent, &overall);

    // Compute the shape of the button_t
    width = overall.width + 60;
    height = ascent + descent + 10;
    x = in_x;
    y = in_y;

    mouseover = 0;
    clicked = 0;
    fg = BlackPixel(display, DefaultScreen(display));
    bg = WhitePixel(display, DefaultScreen(display));

    XSelectInput(display, window,
                 ExposureMask |  KeymapStateMask | StructureNotifyMask |
                 PointerMotionMask | ButtonPressMask | ButtonReleaseMask);

    XFontStruct *font = XLoadQueryFont(display, "fixed");
};

void Button::draw() {
//    Function for drawing the button on the window
    XClearArea(display, window, x, y, width, height, False);

//    change color of the button if mouse is over the button
    if (mouseover) {
        XFillRectangle(display, window, gc, clicked + x, clicked + y, width, height);
        XSetForeground(display, gc, bg);
        XSetBackground(display, gc, fg);
    } else {
        XSetForeground(display, gc, fg);
        XSetBackground(display, gc, bg);
        XDrawRectangle(display, window, gc, x, y, width, height);
    }

//    text coordinates relatively to button size
    int textx, texty;
    textx = x + 15;
    texty = y + height - 3;

//    draw text inside button
    XDrawString(display, window, gc, clicked + textx, clicked + texty,
                text, strlen(text));

    XSetForeground(display, gc, fg);
    XSetBackground(display, gc, bg);
};

void Button::expose() {
    draw();
};





