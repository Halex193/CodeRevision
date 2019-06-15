#include <QtGui/QPainter>
#include "CircleWidget.h"

CircleWidget::CircleWidget(int number, bool finished, QWidget *parent) :
        QWidget(parent), number(number), finished(finished)
{
}

void CircleWidget::paintEvent(QPaintEvent *event)
{
    int scaling = 10;
    QPainter painter{this};
    painter.setPen(Qt::NoPen);

    if (finished)
    {
        painter.setBrush(QBrush{"blue"});
    }
    else
    {
        painter.setBrush(QBrush{"red"});
    }
    painter.drawEllipse(QPoint{rect().width() / 2, rect().height() / 2}, number * scaling, number * scaling);
}

void CircleWidget::updateData(int newNumber, bool newFinished)
{
    number = newNumber;
    finished = newFinished;
    repaint();
}

CircleWidget::~CircleWidget()
= default;