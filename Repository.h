#ifndef CODEREVISION_REPOSITORY_H
#define CODEREVISION_REPOSITORY_H


#include <vector>
#include "Programmer.h"
#include "SourceFile.h"
#include "Observable.h"

class Repository : public Observable
{
    QString programmersFile;
    QString sourceFilesFile;
    std::vector<Programmer> programmers;
    std::vector<SourceFile> sourceFiles;

public:
    Repository(const QString &programmersFile, const QString &sourceFilesFile);

    void readData();

    const std::vector<Programmer> &getProgrammers() const;

    const std::vector<SourceFile> &getSourceFiles() const;

    void add(SourceFile &sourceFile);

    void fileReviewed(SourceFile &sourceFile);

    bool programmerMadeReview(const QString& programmerName);
};


#endif //CODEREVISION_REPOSITORY_H
