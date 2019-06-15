#ifndef CODEREVISION_TESTS_H
#define CODEREVISION_TESTS_H
#include <QDebug>
#include <assert.h>
#include "AppExceptions.h"
#include <vector>
#include <algorithm>
#define TEST true
using namespace std;

void testAdd(Controller& controller)
{
    try
    {
        controller.add("", "");
        assert(false);
    }
    catch (EmptyFileNameException &exception)
    {}

    try
    {
        controller.add("file1", "");
        assert(false);
    }
    catch (DuplicateFileException &exception)
    {}

    controller.add("newFile", "Andy");
    vector<SourceFile> sourceFiles = controller.getRepository().getSourceFiles();
    auto iterator = find(sourceFiles.begin(), sourceFiles.end(), SourceFile{"newFile"});
    assert(iterator != sourceFiles.end());
    SourceFile& sourceFile = *iterator;
    assert(sourceFile.getName() == "newFile");
    assert(sourceFile.getCreator() == "Andy");
    assert(sourceFile.getStatus() == "not_revised");
    assert(sourceFile.getReviewer() == "");
}
void testRevise(Controller& controller)
{
    SourceFile file{"newFile"};
    controller.revise(file, "Daniel");

    vector<SourceFile> sourceFiles = controller.getRepository().getSourceFiles();
    auto iterator = find(sourceFiles.begin(), sourceFiles.end(), SourceFile{"newFile"});
    assert(iterator != sourceFiles.end());
    SourceFile& sourceFile = *iterator;
    assert(sourceFile.getName() == "newFile");
    assert(sourceFile.getCreator() == "Andy");
    assert(sourceFile.getStatus() == "revised");
    assert(sourceFile.getReviewer() == "Daniel");
}
void testAll()
{
    if(TEST)
    {
        Repository repository{"testProgrammers.txt", "testFiles.txt"};
        Controller controller{repository};
        testAdd(controller);
        testRevise(controller);
        qDebug() << "All tests passed!\n";
    }
}
#endif //CODEREVISION_TESTS_H
