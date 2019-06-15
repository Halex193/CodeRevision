#ifndef StatisticsWindow_H
#define StatisticsWindow_H

#include <QWidget>
#include "Controller.h"

namespace Ui
{
    class StatisticsWindow;
}

class StatisticsWindow : public QWidget
{
Q_OBJECT
    Controller &controller;
public:
    explicit StatisticsWindow(Controller &controller, QWidget *parent = nullptr);

    ~StatisticsWindow() override;

private:
    Ui::StatisticsWindow *ui;
};

#endif // StatisticsWindow_H
