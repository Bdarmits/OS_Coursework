///xfontsel///

#include <iostream>
#include "include/window.h"
#include "include/widget.h"
#include "include/text.h"
#include "include/button.h"
#include "include/MyDialog.h"
int DIAL_HEIGHT = 500, DIAL_WIDTH = 900;
int main() {
    MyDialog dialog;
    dialog.init("Party Game Box", 20, 20, DIAL_WIDTH, DIAL_HEIGHT);



    Text text_box;
    text_box.init(dialog.wi, "Welcome to the Party Game Box", DIAL_WIDTH/2,DIAL_HEIGHT/2 - 100, 20, 20,  "24");
    text_box.draw();

    Text text_box1;
    text_box1.init(dialog.wi, "Choose your game", DIAL_WIDTH/2 +30,DIAL_HEIGHT/2 - 70, 20, 20, "16");
    text_box1.draw();

    Button button1;
    button1.init(dialog.wi, 35, 35, "Options");
    button1.draw();


    Button button2;
    button2.init(dialog.wi, 200, 35, "New Game");
    button2.draw();


    dialog.add_widget(text_box);
    dialog.add_widget(text_box1);

    dialog.add_widget(button1);
    dialog.add_widget(button2);


    XSelectInput(dialog.wi.display, dialog.wi.window, KeyPressMask | KeyReleaseMask | ExposureMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);


    XEvent report, report1;
    int temp_res1, temp_res2;

    // loop, for active listening of any events
    while (1) {
        // take event from query
        XNextEvent(dialog.wi.display, &report);

        if (report.type == MotionNotify) {
            if (button1.button_mouseover_changed(&report.xmotion) || button2.button_mouseover_changed(&report.xmotion)) {
                report.type = Expose;
            }
        }
        /* select kind of events we are interested in */

        /* map (show) the window */
//        XMapWindow(dialog.wi.display, dialog.wi.window);

        switch (report.type) {
            // expose event
            case Expose :
                // wait untill all expose events will come
                //next 2 rows are commented as temporary fix -  allow to redraw button
                /*
               if (report.xexpose.count != 0) {
                    break;
               }
                 */
                dialog.wi.gc = XCreateGC(dialog.wi.display, dialog.wi.window, 0, NULL);
                XSetForeground(dialog.wi.display, dialog.wi.gc, BlackPixel (dialog.wi.display, 0));


                //TODO: rewrite with dialog expose
                //dialog.expose();

                text_box.expose();
                text_box1.expose();

                button1.expose();
                button2.expose();


                XFreeGC(dialog.wi.display, dialog.wi.gc);
                XFlush(dialog.wi.display);
                break;
            case ButtonPress:
            case ButtonRelease:
                temp_res1 = button1.is_button_clicked(&(report.xbutton));
                temp_res2 = button2.is_button_clicked(&(report.xbutton));
                if (temp_res1 == BTN_IS_CLICKED) {
                    std::cout << "Button 1 is clicked!!!" << std::endl;
                    MyDialog dialog1;
                    dialog1.init("Party Game Box", 20, 20, DIAL_WIDTH, DIAL_HEIGHT);

                    std::string nickname = "";
                    Text text_box2;
                    text_box2.init(dialog1.wi, nickname.c_str(), DIAL_WIDTH/2,DIAL_HEIGHT/2 - 100, 20, 20,  "24");
                    text_box2.draw();
                    while (1){
                        XNextEvent(dialog1.wi.display, &report1);
                        if (report1.type == KeyPress){

                            KeySym sym1=XLookupKeysym(&report1.xkey, 0);
                            printf( "KeyPress: %s\n", XKeysymToString(sym1) );
                            if(report1.xkey.keycode == 0x09){
                                break;
                            }
                            //nickname.c_str()
                            nickname += XKeysymToString(sym1);
                            text_box2.init(dialog1.wi, nickname.c_str(), DIAL_WIDTH/2,DIAL_HEIGHT/2 - 100, 20, 20,  "24");
                            text_box2.draw();
                            dialog1.add_widget(text_box2);

                        }
                        if (report1.type == Expose){
//                            dialog1.wi.gc = XCreateGC(dialog1.wi.display, dialog1.wi.window, 0, NULL);
//                            XSetForeground(dialog1.wi.display, dialog1.wi.gc, BlackPixel (dialog1.wi.display, 0));
                            text_box2.expose();
//                            XFreeGC(dialog1.wi.display, dialog1.wi.gc);
//                            XFlush(dialog1.wi.display);
                        }
                    }
                    XCloseDisplay(dialog1.wi.display);
                    printf("%s", nickname.c_str());

                }
                else if (temp_res2 == BTN_IS_CLICKED) {
                    std::cout << "Button 2 is clicked!!!" << std::endl;
                }
                break;
//            case KeyPress :
//                // in case of press of any key, close connection and exit from the program
//                if ( report.xkey.keycode == 0x09 ){
//                    XCloseDisplay(dialog.wi.display);
////                    _exit(0);
//                    break;
//                }
////                    break;

        }
        if (report.type == KeyPress){
            KeySym sym=XLookupKeysym(&report.xkey, 0);
            printf( "KeyPress: %s\n", XKeysymToString(sym) );
            if(report.xkey.keycode == 0x09){
                break;
            }
        }else if (report.type == KeyRelease)
        {
            KeySym sym=XLookupKeysym(&report.xkey, 0);
            printf( "KeyPress: %s\n", XKeysymToString(sym) );
        }

    }
    XCloseDisplay(dialog.wi.display);

    return 0;
}