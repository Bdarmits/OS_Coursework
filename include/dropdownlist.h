#ifndef PROJECT_DROPDOWNLIST_H
#define PROJECT_DROPDOWNLIST_H

#include "widget.h"
#include "button.h"
#include "MyDialog.h"

class Dropdownlist : public Button {
public:
    int activ_radio = 0;
    int is_active = 0;
    MyDialog dialogddl;

    button_clicked_state_t is_button_clicked(const XButtonEvent *xbutton) override;
    void spam_menu();
    void destroy_menu();
    void draw() override;


};

#endif //PROJECT_DROPDOWNLIST_H
