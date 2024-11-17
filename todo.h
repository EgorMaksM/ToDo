#ifndef TODO_H
#define TODO_H

#include <QString>
#include <QtGlobal>
#include <QDateTime>

class ToDo
{
public:
    ToDo();

private:
    QString Name;
    QString Description;
    QDateTime DateTime;
};

#endif
