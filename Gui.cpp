#include "Gui.h"
#include "ProgrammerWindow.h"
#include "StatisticsWindow.h"
#include <vector>
using namespace std;

Gui::Gui(Controller &controller) : controller(controller)
{}

void Gui::show()
{
    auto *window = new StatisticsWindow{controller};
    window->show();

    vector<Programmer> programmers = controller.getRepository().getProgrammers();
    for (auto &programmer : programmers)
    {
        auto *programmerWindow = new ProgrammerWindow{controller, programmer};
        programmerWindow->show();
    }
}
