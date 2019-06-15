#include "ProgrammerWindow.h"
#include "ui_programmerwindow.h"
#include "AppExceptions.h"
#include <vector>
#include <QtWidgets/QMessageBox>
#include <algorithm>

using namespace std;

ProgrammerWindow::ProgrammerWindow(Controller &controller, Programmer &programmer, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ProgrammerWindow), controller(controller), programmerName(programmer.getName())
{
    ui->setupUi(this);
    setWindowTitle(programmer.getName());

    QObject::connect(ui->addButton, &QPushButton::clicked, this, &ProgrammerWindow::addButtonClicked);
    QObject::connect(ui->reviseButton, &QPushButton::clicked, this, &ProgrammerWindow::revisedButtonClicked);
    QObject::connect(ui->listWidget, &QListWidget::currentRowChanged, this, &ProgrammerWindow::selectedItemChanged);

    controller.getRepository().attach(this);
    update();
}

ProgrammerWindow::~ProgrammerWindow()
{
    delete ui;
}

void ProgrammerWindow::update()
{
    sourceFiles = controller.getRepository().getSourceFiles();
    sort(sourceFiles.begin(), sourceFiles.end(), [](SourceFile &sourceFile1, SourceFile &sourceFile2)
    { return sourceFile1.getName() < sourceFile2.getName(); });

    ui->listWidget->clear();
    QFont font{"Times", 9};
    for (auto &file : sourceFiles)
    {
        QListWidgetItem *item = new QListWidgetItem{file.toQString()};
        bool revised = (file.getStatus() == "revised");
        font.setBold(!revised);
        if(revised)
            item->setBackgroundColor("lightgreen");
        item->setFont(font);
        ui->listWidget->addItem(item);
    }
    vector<Programmer> programmers = controller.getRepository().getProgrammers();
    auto iterator = std::find(programmers.begin(), programmers.end(), Programmer{programmerName});
    Programmer &programmer = *iterator;
    setRevised(programmer.getRevisedFiles(), programmer.getTotalFiles());
}

void ProgrammerWindow::addButtonClicked()
{
    QString sourceFileName = ui->fileLineEdit->text();
    try
    {
        controller.add(sourceFileName, programmerName);
    }
    catch (AppException &exception)
    {
        QMessageBox::critical(nullptr, "Error", exception.what(), QMessageBox::Ok);
    }
}

void ProgrammerWindow::revisedButtonClicked()
{
    int row = ui->listWidget->currentRow();
    if (row >= 0)
    {
        SourceFile &selectedFile = sourceFiles[row];
        bool allRevised = controller.revise(selectedFile, programmerName);
        if (allRevised)
        {
            QMessageBox::information(nullptr, "Hooray!", "You have revised all the files you had to!", QMessageBox::Ok);
        }
    }
}

void ProgrammerWindow::setRevised(int revisedFiles, int totalFiles)
{
    ui->revisedLabel->setText(QString{"Revised: "} + QString::number(revisedFiles));
    ui->unrevisedLabel->setText(QString{"Unrevised: "} + QString::number((totalFiles - revisedFiles)));
}

void ProgrammerWindow::selectedItemChanged()
{
    int row = ui->listWidget->currentRow();
    if (row >= 0)
    {
        SourceFile &selectedFile = sourceFiles[row];
        bool enabled = selectedFile.getStatus() == "not_revised" && selectedFile.getCreator() != programmerName;
        ui->reviseButton->setEnabled(enabled);
    }
}
