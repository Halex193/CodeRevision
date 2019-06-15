#include "StatisticsWindow.h"
#include "ui_statisticswindow.h"
#include "CircleWidget.h"
#include <vector>
#include <QtWidgets/QLabel>

using namespace std;

StatisticsWindow::StatisticsWindow(Controller &controller, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::StatisticsWindow), controller(controller)
{
    ui->setupUi(this);
    setWindowTitle("Statistics");
    vector<Programmer> programmers = controller.getRepository().getProgrammers();
    for (auto &programmer : programmers)
    {
        auto *layout = new QHBoxLayout{};
        bool finished = (programmer.getRevisedFiles() >= programmer.getTotalFiles());
        auto *circleWidget = new CircleWidget{programmer.getRevisedFiles(), finished};
        layout->addWidget(circleWidget);
        auto *label = new QLabel{programmer.getName()};
        QFont font{"Times", 9};
        label->setFont(font);
        layout->addWidget(label);
        ui->verticalLayout->addLayout(layout);
        circles.push_back(circleWidget);
    }
    controller.getRepository().attach(this);
    update();
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::update()
{
    vector<Programmer> programmers = controller.getRepository().getProgrammers();
    int i=0;
    for (auto &programmer : programmers)
    {
        bool finished = (programmer.getRevisedFiles() >= programmer.getTotalFiles());
        circles[i]->updateData(programmer.getRevisedFiles(), finished);
        i++;
    }
}

