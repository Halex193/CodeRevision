#ifndef CODEREVISION_CONTROLLER_H
#define CODEREVISION_CONTROLLER_H


#include "Repository.h"

class Controller
{
    Repository &repository;
public:
    Repository &getRepository() const;

public:
    explicit Controller(Repository &repository);

    void add(const QString& sourceFileName, const QString& programmerName);

    bool revise(SourceFile& sourceFile, QString programmerName);
};


#endif //CODEREVISION_CONTROLLER_H
