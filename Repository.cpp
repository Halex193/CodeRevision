#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>
#include "Repository.h"
#include "AppExceptions.h"
#include <algorithm>
Repository::Repository(const QString &programmersFile, const QString &sourceFilesFile) : programmersFile(
        programmersFile), sourceFilesFile(sourceFilesFile)
{
    readData();
}

void Repository::readData()
{
    QFile file{programmersFile};
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, "File not found", "The programmer file was not found", QMessageBox::Ok);
    }
    QTextStream in{&file};

    programmers.clear();
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(QRegExp{"; *"});
        Programmer programmer{fields[0], fields[1].toInt(), fields[2].toInt()};
        programmers.push_back(programmer);
    }

    QFile file2{sourceFilesFile};
    if (!file2.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, "File not found", "The source files file was not found", QMessageBox::Ok);
    }
    QTextStream in2{&file2};

    sourceFiles.clear();
    while (!in2.atEnd())
    {
        QString line = in2.readLine();
        QStringList fields = line.split(QRegExp{"; *"});
        SourceFile sourceFile{fields[0], fields[1], fields[2], fields[3]};
        sourceFiles.push_back(sourceFile);
    }
}

const std::vector<Programmer> &Repository::getProgrammers() const
{
    return programmers;
}

const std::vector<SourceFile> &Repository::getSourceFiles() const
{
    return sourceFiles;
}

void Repository::add(SourceFile &sourceFile)
{
    auto iterator = find(sourceFiles.begin(), sourceFiles.end(), sourceFile);
    if (iterator != sourceFiles.end())
    {
        throw DuplicateFile{};
    }
    sourceFiles.push_back(sourceFile);
    notify();
}

void Repository::fileReviewed(SourceFile &sourceFile)
{
    auto iterator = std::find(sourceFiles.begin(), sourceFiles.end(), sourceFile);
    sourceFiles.erase(iterator);
    sourceFiles.push_back(sourceFile);
}

bool Repository::programmerMadeReview(const QString& programmerName)
{
    return false;
}
