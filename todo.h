#ifndef TODO_H
#define TODO_H

#include <QString>
#include <QtGlobal>
#include <QDateTime>

class ToDo
{
public:
    ToDo(const QString name = QString(""), const QString descr = QString(""), const QDateTime dateTime = QDateTime());

public:
    QString Name;
    QString Description;
    QDateTime DateTime;
};

#endif
