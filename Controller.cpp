#include "Controller.h"
#include "AppExceptions.h"
Controller::Controller(Repository &repository) : repository(repository)
{}

Repository &Controller::getRepository() const
{
    return repository;
}

void Controller::add(const QString &sourceFileName, const QString &programmerName)
{
    if (sourceFileName.isEmpty())
    {
        throw EmptyFileName{};
    }
    SourceFile sourceFile{sourceFileName, "not_revised", programmerName, ""};
    repository.add(sourceFile);
}

bool Controller::revise(SourceFile &sourceFile, QString programmerName)
{
    sourceFile.setReviewer(programmerName);
    sourceFile.setStatus("revised");
    repository.fileReviewed(sourceFile);
    return repository.programmerMadeReview(programmerName);
}
