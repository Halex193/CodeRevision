#ifndef ProgrammerWindow_H
#define ProgrammerWindow_H

#include <QWidget>
#include "Controller.h"

namespace Ui
{
    class ProgrammerWindow;
}

class ProgrammerWindow : public QWidget, public Observer
{
Q_OBJECT

    Controller &controller;
    QString programmerName;
    std::vector <SourceFile> sourceFiles;
public:
    void update() override;

public:
    explicit ProgrammerWindow(Controller &controller, Programmer &programmer, QWidget *parent = nullptr);

    ~ProgrammerWindow() override;

    void addButtonClicked();

    void revisedButtonClicked();

    void selectedItemChanged();

private:
    Ui::ProgrammerWindow *ui;

    void setRevised(int revisedFiles, int totalFiles);
};

#endif // ProgrammerWindow_H
