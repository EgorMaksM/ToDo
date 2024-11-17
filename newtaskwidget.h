#ifndef NEWTASKWIDGET_H
#define NEWTASKWIDGET_H

#include <QWidget>
#include <QCalendarWidget>
#include <QDateTime>
#include "todo.h"

namespace Ui {
class newTaskWidget;
}

class newTaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit newTaskWidget(QWidget *parent = nullptr);
    ~newTaskWidget();

    QDateTime selectedDateTime;

private:
    Ui::newTaskWidget *ui;

private slots:
    void onTimeChanged(const QTime &newTime);
    void onDateChanged();
    void onDoneButtonClicked();
};

#endif // NEWTASKWIDGET_H
