#ifndef CODEREVISION_SOURCEFILE_H
#define CODEREVISION_SOURCEFILE_H


#include <QtCore/QCharRef>

class SourceFile
{
    QString name;
public:
    explicit SourceFile(const QString &name);

private:
    QString status;
    QString creator;
    QString reviewer;
public:
    bool operator==(const SourceFile &rhs) const;

    bool operator!=(const SourceFile &rhs) const;

public:
    void setStatus(const QString &status);

    void setCreator(const QString &creator);

    void setReviewer(const QString &reviewer);

public:
    const QString &getName() const;

    const QString &getStatus() const;

    const QString &getCreator() const;

    const QString &getReviewer() const;

public:
    SourceFile(const QString &name, const QString &status, const QString &creator, const QString &reviewer);

    QString toQString();
};


#endif //CODEREVISION_SOURCEFILE_H
