#include "filestream.h"

/* Get an std::vector of all the existing tasks */
std::vector<ToDo *> FileStream::readAllTasks()
{
    std::vector<ToDo*> TaskArray;
    QFile file(FilePath);

    if (!file.exists()) {
        qDebug() << "File does not exist. Returning an empty task list.";
        return TaskArray;
    }

    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);

        while (!in.atEnd()) {
            QString name, description;
            QDateTime dateTime;

            in >> name >> description >> dateTime;

            ToDo* Task = new ToDo();
            Task->Name = name;
            Task->Description = description;
            Task->DateTime = dateTime;

            TaskArray.push_back(Task);
        }
        file.close();
        //qDebug() << "Tasks read successfully.";
    } else {
        //qDebug() << "Failed to open file for reading!";
    }

    return TaskArray;
}

void FileStream::writeTask(ToDo *Task)
{
    QFile file(FilePath);
    if (file.open(QIODevice::Append)) {
        QDataStream out(&file);
        out << Task->Name << Task->Description << Task->DateTime;
        file.close();
        //qDebug() << "Task written successfully.";
    } else {
        //qDebug() << "Failed to open file for appending!";
    }
}

/* Write an std::vector of tasks to static storage after clearing it's contents */
void FileStream::writeTaskArray(std::vector<ToDo*> TaskArray)
{
    QFile file(FilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QDataStream out(&file);
        for (const auto &Task : TaskArray) {
            out << Task->Name << Task->Description << Task->DateTime;
        }
        file.close();
        qDebug() << "Tasks written successfully.";
    } else {
        qDebug() << "Failed to open file for writing!";
    }
}

/* Delete a given task from static storage */
void FileStream::deleteTask(ToDo* Task)
{
    QFile file(FilePath);

    std::vector<ToDo*> vector = readAllTasks();
    QList<ToDo*> allObjects;
    allObjects.reserve(vector.size());
    std::copy(vector.begin(), vector.end(), std::back_inserter(allObjects));

    allObjects.removeAll(Task);
    delete Task;

    // Rewrite the file with the remaining objects
    writeTaskArray(std::vector(allObjects.constBegin(), allObjects.constEnd()));
}

void FileStream::clearAllTasks(std::vector<ToDo*>& tasks)
{
    QFile file(FilePath);

    // Open file for writing, truncating its contents
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "All tasks cleared from file.";
        file.close();
    } else {
        qDebug() << "Failed to open file for clearing!";
    }

    // Ensure we clear the input vector
    tasks.clear();
}
