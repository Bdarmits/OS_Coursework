#ifndef PROJECT_SSBUTTON_H
#define PROJECT_SSBUTTON_H

#include "widget.h"
#include "button.h"

class SSbutton : public Button {
public:
    int activ_radio = 0;
    int is_active = 0;
    MyDialog dialogddl;

    button_clicked_state_t is_button_clicked(const XButtonEvent *xbutton) override;
    XImage* create_ximage(Display *display, Visual *visual, Window window);
    void spam_menu(MyDialog dialog);
    void draw() override;
};

#endif //PROJECT_SSBUTTON_H
