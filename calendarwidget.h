#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QLayout>
#include <QList>
#include <QFontDatabase>
#include <QComboBox>
#include <QSpinBox>
#include <QToolButton>
#include <QDateTime>
#include <QDialog>

#include "trianglebutton.h"
#include "monthcombobox.h"
#include "myspinbox.h"
#include "smoothscrollarea.h"
#include "todo.h"
#include "taskwidget.h"
#include "proxyoverlay.h"
#include "filestream.h"
#include "plusbutton.h"
#include "newtaskwidget.h"

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
    void onDateChanged();
    void onNextWeek();
    void onPrevWeek();
    void updateCalendar();
    void setWeek(int index);
    void onNewTask();

    std::array<std::array<QList<ProxyOverlay*>, 24>, 7> taskList;
    QDateTime currentDate;

    QVBoxLayout *mainLayout;

    QWidget *topWidget;
    QVBoxLayout *topLayout;

    QWidget *monthYearWidget;
    QHBoxLayout *monthYearLayout;

    QWidget *weekWidget;
    QHBoxLayout *weekLayout;
    MonthComboBox *monthComboBox;
    MySpinBox *yearSpinBox;
    TriangleButton *prevWeekButton;
    QLabel* weekNumber;
    TriangleButton *nextWeekButton;
    PlusButton *newTask;
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
