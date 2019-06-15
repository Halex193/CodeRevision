#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "Gui.h"
#include "tests.h"

int main(int argc, char** argv)
{
    QApplication application{argc, argv};
    testAll();
    Repository repository{"programmers.txt", "files.txt"};
    Controller controller{repository};
    Gui gui{controller};
    gui.show();
    return QApplication::exec();
}