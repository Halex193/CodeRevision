#ifndef CODEREVISION_APPEXCEPTIONS_H
#define CODEREVISION_APPEXCEPTIONS_H

#include <stdexcept>
class AppException : public std::runtime_error
{
public:
    explicit AppException(const std::string &arg) : runtime_error(arg)
    {}
};

class EmptyFileName : public AppException
{
public:
    explicit EmptyFileName() : AppException("The file name is empty!")
    {}
};

class DuplicateFile : public AppException
{
public:
    explicit DuplicateFile() : AppException("The file already exists!")
    {}
};
#endif //CODEREVISION_APPEXCEPTIONS_H
