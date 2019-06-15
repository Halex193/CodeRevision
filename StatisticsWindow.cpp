#include "StatisticsWindow.h"
#include "ui_statisticswindow.h"

StatisticsWindow::StatisticsWindow(Controller &controller, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::StatisticsWindow), controller(controller)
{
    ui->setupUi(this);
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}