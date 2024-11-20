#include "todo.h"

ToDo::ToDo(const QString name, const QString descr, const QDateTime dateTime) : Name(name), Description(descr), DateTime(dateTime)
{

}

bool ToDo::operator==(const ToDo &other) const
{
    return (this->Name == other.Name &&
            this->Description == other.Description &&
            this->DateTime == other.DateTime);
}
