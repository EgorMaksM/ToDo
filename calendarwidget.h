#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QLayout>
#include <QList>
#include <QFontDatabase>

#include "smoothscrollarea.h"
#include "todo.h"
#include "taskwidget.h"
#include "proxyoverlay.h"
#include "filestream.h"

namespace Ui {
class CalendarWidget;
}

class CalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = nullptr, FileStream* filemgr = nullptr);
    ~CalendarWidget();

    ProxyOverlay* AddTask(ToDo* task);
    void DeleteTask(ProxyOverlay* proxy);
    void FindWeek(std::vector<ToDo*> tasks, int WeekIndex = QDateTime::currentDateTime().date().weekNumber());
    void SetWeek(int year = QDateTime::currentDateTime().date().year(), int weekNumber = QDateTime::currentDateTime().date().weekNumber());
    std::array<std::array<QList<ProxyOverlay*>, 24>, 7> taskList;

    QVBoxLayout *mainLayout;
    QWidget *headerWidget;
    QHBoxLayout *headerLayout;
    SmoothScrollArea *scrollArea;
    QWidget *scrollContentWidget;
    QGridLayout *scrollContentLayout;
    QWidget *gridWidget;
    QGridLayout *gridLayout;

    FileStream* FILEMGR;

private:
    Ui::CalendarWidget *ui;
};

#endif // CALENDARWIDGET_H
