#ifndef StatisticsWindow_H
#define StatisticsWindow_H

#include <QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include "Controller.h"
#include "CircleWidget.h"

namespace Ui
{
    class StatisticsWindow;
}

class StatisticsWindow : public QWidget, public Observer
{
Q_OBJECT
    Controller &controller;
    std::vector<CircleWidget*> circles;
    std::vector<QLabel*> labels;
public:
    explicit StatisticsWindow(Controller &controller, QWidget *parent = nullptr);

    ~StatisticsWindow() override;

    void update() override;

private:
    Ui::StatisticsWindow *ui;

};

#endif // StatisticsWindow_H
