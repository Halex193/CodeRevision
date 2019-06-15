#ifndef CODEREVISION_GUI_H
#define CODEREVISION_GUI_H


#include "Controller.h"

class Gui
{
    Controller &controller;
public:
    explicit Gui(Controller &controller);

    void show();
};


#endif //CODEREVISION_GUI_H
