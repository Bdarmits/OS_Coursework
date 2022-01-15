///xfontsel///
#include <iostream>
#include "include/window.h"
#include "include/widget.h"
#include "include/text.h"
#include "include/button.h"
#include "include/MyDialog.h"
#include "include/radiobutton.h"
#include "include/TextInputField.h"
#include "include/dropdownlist.h"
#include "include/SSbutton.h"
#include <X11/Xlib.h>



XImage *create_ximage(Display *display, Visual *visual, Window window)
{

    XWindowAttributes attr = {};
    XGetWindowAttributes(display, window, &attr);

    auto widthimg = attr.width;
    auto heightimg = attr.height;

    return XGetImage(display, window, 0, 0, widthimg, heightimg, AllPlanes, ZPixmap);
}

int main() {
    int DIAL_HEIGHT = 500, DIAL_WIDTH = 900;

    MyDialog dialog;
    dialog.init("Best GUI Presentation", 200, 200, DIAL_WIDTH, DIAL_HEIGHT);

    Text text_box;
    text_box.init(dialog.wi, "Welcome to the Best X11 GUI", DIAL_WIDTH/2,DIAL_HEIGHT/2 - 100, 20, 20,  "24");

    Text text_box1;
    text_box1.init(dialog.wi, "Enjoy! :)", DIAL_WIDTH/2 +30,DIAL_HEIGHT/2 - 70, 20, 20, "16");

    Button button1;
    button1.init(dialog.wi, 35, 35, "Button1");

    RadioButton rd1;
    rd1.init(dialog.wi, 400, 35, "radio test");

    TextInputField tif;
    tif.init(dialog.wi, 600, 35, "" );

    Dropdownlist ddl;
    ddl.init(dialog.wi, 35, 100, "dropdown");

    Button button2;
    button2.init(dialog.wi, 200, 35, "Button2");

    SSbutton ssbutton;
    ssbutton.init(dialog.wi, 200, 100, "Take a Picture");

    XSelectInput(dialog.wi.display, dialog.wi.window, KeyPressMask | KeyReleaseMask | ExposureMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);
    XEvent report, report1, report2;
    int temp_res1, temp_res2, temp_res3, temp_res4, temp_res5, temp_res6;



    // loop, for active listening of any events
    while (1) {
        // take event from query
        XNextEvent(dialog.wi.display, &report);

        if (report.type == MotionNotify) {
            if (button1.button_mouseover_changed(&report.xmotion) || button2.button_mouseover_changed(&report.xmotion)
                || rd1.button_mouseover_changed(&report.xmotion) || tif.button_mouseover_changed(&report.xmotion)
                || ddl.button_mouseover_changed(&report.xmotion) || ssbutton.button_mouseover_changed(&report.xmotion) ) {
                report.type = Expose;
            }
        }
        /* select kind of events we are interested in */
        /* map (show) the window */

        switch (report.type) {
            // expose event
            case Expose :
                dialog.wi.gc = XCreateGC(dialog.wi.display, dialog.wi.window, 0, NULL);
                XSetForeground(dialog.wi.display, dialog.wi.gc, BlackPixel (dialog.wi.display, 0));

                text_box.expose();
                text_box1.expose();
                button1.expose();
                button2.expose();
                rd1.expose();
                tif.expose();
                ddl.expose();
                ssbutton.expose();

                XFreeGC(dialog.wi.display, dialog.wi.gc);
                XFlush(dialog.wi.display);
                break;
            case ButtonPress:
            case ButtonRelease:
                temp_res1 = button1.is_button_clicked(&(report.xbutton));
                temp_res2 = button2.is_button_clicked(&(report.xbutton));
                temp_res3 = rd1.is_button_clicked(&(report.xbutton));
                temp_res4 = tif.is_button_clicked(&(report.xbutton));
                temp_res5 = ddl.is_button_clicked(&(report.xbutton));
                temp_res6 = ssbutton.is_button_clicked(&(report.xbutton));

                if (temp_res6 == BTN_IS_CLICKED){
                    if (ssbutton.is_active == 1){
                        ssbutton.is_active = 0;
                    }
                    ssbutton.spam_menu(dialog);
                }
                else if (temp_res5 == BTN_IS_CLICKED ){
                    if (ddl.is_active == 1){
                        ddl.destroy_menu();
                        ddl.is_active = 0;
                    }
                    std::cout << " Dropdown  is clicked!!!" << std::endl;
                    ddl.spam_menu();
                }
                else if (temp_res1 == BTN_IS_CLICKED) {
                    std::cout << "Button 1 is clicked!!!" << std::endl;

                }
                else if (temp_res2 == BTN_IS_CLICKED) {
                    std::cout << "Button 2 is clicked!!!" << std::endl;
                }
                else if (temp_res3 == BTN_IS_CLICKED) {
                    std::cout << "Radio Button  is clicked!!!" << std::endl;
                    rd1.expose();


                }
                break;

        }
        if (report.type == KeyPress  ){
            if(temp_res4 == BTN_IS_CLICKED ){
                tif.add_text(report);
            }else if(report.xkey.keycode == 0x09 ){
                break;
            }
        }else if (report.type == KeyRelease)
        {
            KeySym sym1=XLookupKeysym(&report.xkey, 0);
            printf( "KeyRelease: %s\n", XKeysymToString(sym1) );
        }

    }
    XCloseDisplay(dialog.wi.display);
    return 0;
}