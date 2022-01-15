#ifndef PROJECT_TEXTINPUTFIELD_H
#define PROJECT_TEXTINPUTFIELD_H

#include "widget.h"
#include "button.h"

class TextInputField : public Button {
public:
    int activ_radio = 0;
    std::string nickname = "";


    button_clicked_state_t is_button_clicked(const XButtonEvent *xbutton) override;
    void add_text(XEvent report);
//    void remove_text();
    void draw() override;


};
#endif //PROJECT_TEXTINPUTFIELD_H
