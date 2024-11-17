#include "mainwindow.h"

#include "./ui_mainwindow.h"

#include <QTextEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QCalendarWidget>
#include <QTimeEdit>

#include "todo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    newTask = new newTaskWidget(this);

    stackedWidget->setGeometry(0, 35, 1920, 1045);
    stackedWidget->addWidget(newTask);

    QPlainTextEdit* nameInput = newTask->findChild<QPlainTextEdit*>("nameInput");
    QTextEdit* descriptionInput = newTask->findChild<QTextEdit*>("descriptionInput");
    QTimeEdit* timeInput = newTask->findChild<QTimeEdit*>("timeEdit");
    QCalendarWidget* dateInput = newTask->findChild<QCalendarWidget*>("dateEdit");
    QPushButton* doneButton = newTask->findChild<QPushButton*>("doneButton");

    dateInput->setGridVisible(true);
    dateInput->setSelectionMode(QCalendarWidget::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}
