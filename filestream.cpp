#include "filestream.h"

/* Get an std::vector of all the existing tasks */
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

/* Add a task to static storage */
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

/* Write an std::vector of tasks to static storage after clearing it's contents */
void FileStream::writeTaskArray(const std::vector<ToDo>& TaskArray)
{
    QFile file(FilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QDataStream out(&file);
        for (const auto &Task : TaskArray) {
            out << Task.Name << Task.Description << Task.DateTime;
        }
        file.close();
        qDebug() << "Tasks written successfully.";
    } else {
        qDebug() << "Failed to open file for writing!";
    }
}

/* Delete a given task from static storage */
void FileStream::deleteTask(const ToDo& Task)
{
    QFile file(FilePath);

    std::vector<ToDo> vector = readAllTasks();
    QList<ToDo> allObjects;
    allObjects.reserve(vector.size());
    std::copy(vector.begin(), vector.end(), std::back_inserter(allObjects));

    allObjects.removeAll(Task);

    // Rewrite the file with the remaining objects
    writeTaskArray(std::vector(allObjects.constBegin(), allObjects.constEnd()));
}
