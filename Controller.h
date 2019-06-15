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

    /**
     * Adds a source file to the repository
     * The added file will have the status "not_revised" and no reviewer
     * @param sourceFileName The name of the new file
     * @param programmerName The name of the programmer that created the file
     * @throws EmptyFileNameException if the given sourceFileName is empty
     * @throws DuplicateFileException if a file with the same name already exists
     */
    void add(const QString& sourceFileName, const QString& programmerName);

    /**
     * Marks a file as being reviewed
     * @param sourceFile The data of the source file that will be marked as reviewed
     * @param programmerName The name of the programmer that reviewed the file
     * @return true - if the programmer fulfilled his total review milestone
     *         false - otherwise
     */
    bool revise(SourceFile& sourceFile, QString programmerName);
};


#endif //CODEREVISION_CONTROLLER_H
