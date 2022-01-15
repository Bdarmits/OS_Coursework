#ifndef PROJECT_RADIOBUTTON_H
#define PROJECT_RADIOBUTTON_H

#include "widget.h"
#include "button.h"

class RadioButton : public Button    {
public:
    int activ_radio = 0;
    button_clicked_state_t is_button_clicked(const XButtonEvent* xbutton ) override;
    void draw() override;
};

#endif //PROJECT_RADIOBUTTON_H
