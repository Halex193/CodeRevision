#ifndef CODEREVISION_APPEXCEPTIONS_H
#define CODEREVISION_APPEXCEPTIONS_H

#include <stdexcept>
class AppException : public std::runtime_error
{
public:
    explicit AppException(const std::string &arg) : runtime_error(arg)
    {}
};

class EmptyFileNameException : public AppException
{
public:
    explicit EmptyFileNameException() : AppException("The file name is empty!")
    {}
};

class DuplicateFileException : public AppException
{
public:
    explicit DuplicateFileException() : AppException("The file already exists!")
    {}
};
#endif //CODEREVISION_APPEXCEPTIONS_H
