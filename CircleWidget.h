#ifndef CircleWidget_H
#define CircleWidget_H

#include <QWidget>

class CircleWidget : public QWidget
{
Q_OBJECT
    int number;
    bool finished;
public:
    explicit CircleWidget(int number, bool finished, QWidget *parent = nullptr);

    ~CircleWidget() override;

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    void updateData(int newNumber, bool newFinished);
};

#endif // CircleWidget_H
