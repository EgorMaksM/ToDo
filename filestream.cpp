#include "filestream.h"

std::vector<ToDo> FileStream::readAllTasks()
{
    std::vector<ToDo> TaskArray;
    QFile file(FilePath);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        while (!in.atEnd()) {
            ToDo Task;
            in >> Task.Name >> Task.Description >> Task.DateTime;
            TaskArray.push_back(Task);
        }
        file.close();
        qDebug() << "Tasks read successfully.";
    } else {
        qDebug() << "Failed to open file for reading!";
    }
    return TaskArray;
}

void FileStream::writeTask(const ToDo& Task)
{
    QFile file(FilePath);
    if (file.open(QIODevice::Append)) {
        QDataStream out(&file);
        out << Task.Name << Task.Description << Task.DateTime;
        file.close();
        qDebug() << "Task written successfully.";
    } else {
        qDebug() << "Failed to open file for appending!";
    }
}

void FileStream::writeTaskArray(const std::vector<ToDo>& TaskArray)
{
    QFile file(FilePath);
    if (file.open(QIODevice::Append)) {
        QDataStream out(&file);
        for (const auto &Task : TaskArray) {
            out << Task.Name << Task.Description << Task.DateTime;
        }
        file.close();
        qDebug() << "Tasks written successfully.";
    } else {
        qDebug() << "Failed to open file for appending!";
    }
}
