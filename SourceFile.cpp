#include "SourceFile.h"

SourceFile::SourceFile(const QString &name, const QString &status, const QString &creator, const QString &reviewer)
        : name(name), status(status), creator(creator), reviewer(reviewer)
{}

const QString &SourceFile::getName() const
{
    return name;
}

const QString &SourceFile::getStatus() const
{
    return status;
}

const QString &SourceFile::getCreator() const
{
    return creator;
}

const QString &SourceFile::getReviewer() const
{
    return reviewer;
}

void SourceFile::setStatus(const QString &status)
{
    SourceFile::status = status;
}

void SourceFile::setCreator(const QString &creator)
{
    SourceFile::creator = creator;
}

void SourceFile::setReviewer(const QString &reviewer)
{
    SourceFile::reviewer = reviewer;
}

bool SourceFile::operator==(const SourceFile &rhs) const
{
    return name == rhs.name;
}

bool SourceFile::operator!=(const SourceFile &rhs) const
{
    return !(rhs == *this);
}

QString SourceFile::toQString()
{
    return name + " - " + status + " - Created by: " + creator + " - Reviewed by: " + reviewer;
}
