#include "Programmer.h"

Programmer::Programmer(const QString &name, int revisedFiles, int totalFiles) : name(name), revisedFiles(revisedFiles),
                                                                                totalFiles(totalFiles)
{}

const QString &Programmer::getName() const
{
    return name;
}

int Programmer::getRevisedFiles() const
{
    return revisedFiles;
}

int Programmer::getTotalFiles() const
{
    return totalFiles;
}

void Programmer::setRevisedFiles(int revisedFiles)
{
    Programmer::revisedFiles = revisedFiles;
}

void Programmer::setTotalFiles(int totalFiles)
{
    Programmer::totalFiles = totalFiles;
}

bool Programmer::operator==(const Programmer &rhs) const
{
    return name == rhs.name;
}

bool Programmer::operator!=(const Programmer &rhs) const
{
    return !(rhs == *this);
}

Programmer::Programmer(const QString &name) : name(name), revisedFiles{0}, totalFiles{0}
{}
