#ifndef CODEREVISION_PROGRAMMER_H
#define CODEREVISION_PROGRAMMER_H


#include <QtCore/QCharRef>

class Programmer
{
    QString name;
    int revisedFiles;
public:
    explicit Programmer(const QString &name);

public:
    bool operator==(const Programmer &rhs) const;

    bool operator!=(const Programmer &rhs) const;

public:
    void setRevisedFiles(int revisedFiles);

    void setTotalFiles(int totalFiles);

private:
    int totalFiles;
public:
    const QString &getName() const;

    int getRevisedFiles() const;

    int getTotalFiles() const;

public:
    Programmer(const QString &name, int revisedFiles, int totalFiles);
};


#endif //CODEREVISION_PROGRAMMER_H
