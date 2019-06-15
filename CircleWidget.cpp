#include <QtGui/QPainter>
#include "CircleWidget.h"

CircleWidget::CircleWidget(int number, bool finished, QWidget *parent) :
        QWidget(parent), number(number), finished(finished)
{
}

void CircleWidget::paintEvent(QPaintEvent *event)
{
    int scaling = 3;
    QPainter painter{this};
    painter.drawEllipse(QPoint{rect().width() / 2, rect().height() / 2}, number*scaling, number*scaling);
}

void CircleWidget::updateData()
{

}

CircleWidget::~CircleWidget()
= default;