#ifndef TODO_H
#define TODO_H

#include <QString>
#include <QtGlobal>
#include <QDateTime>

class ToDo
{
public:
    ToDo(QString name, QString descr, QDateTime dateTime);

public:
    QString Name;
    QString Description;
    QDateTime DateTime;
};

#endif
