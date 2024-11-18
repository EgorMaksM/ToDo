#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <vector>
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include "todo.h"

class FileStream
{
public:
    FileStream(QString filePath = QCoreApplication::applicationDirPath() + "/tasks.dat")
        : FilePath(filePath)
    {
    };

    std::vector<ToDo> readAllTasks();
    void writeTask(const ToDo& Task);
    void writeTaskArray(const std::vector<ToDo>& taskArray);
    void deleteTask(const ToDo& Task);

private:
    QString FilePath;
};

#endif // FILESTREAM_H
