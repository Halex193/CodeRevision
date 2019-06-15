#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "Gui.h"

int main(int argc, char** argv)
{
    QApplication application{argc, argv};
    Repository repository{"programmers.txt", "files.txt"};
    Controller controller{repository};
    Gui gui{controller};
    gui.show();
    return QApplication::exec();
}