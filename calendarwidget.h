#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>

namespace Ui {
class CalendarWidget;
}

class CalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = nullptr);
    ~CalendarWidget();

    QVBoxLayout *mainLayout;
    QWidget *headerWidget;
    QHBoxLayout *headerLayout;
    QScrollArea *scrollArea;
    QWidget *scrollContentWidget;
    QGridLayout *scrollContentLayout;
    QWidget *gridWidget;
    QGridLayout *gridLayout;

private:
    Ui::CalendarWidget *ui;
};

#endif // CALENDARWIDGET_H
