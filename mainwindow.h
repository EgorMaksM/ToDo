#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QCalendarWidget>
#include <QTimeEdit>

#include "todo.h"
#include "newtaskwidget.h"
#include "taskwidget.h"
#include "calendarwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //QStackedWidget* stackedWidget;
    //newTaskWidget* newTask;
    CalendarWidget* calendar;
    TaskWidget *todo1;
    QPushButton *green;
    QPushButton *yellow;
    QPushButton *blue;

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
