#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //stackedWidget = new QStackedWidget(this);
    //newTask = new newTaskWidget(this);
    todo1 = new TaskWidget(this, "Name", "Description: LALALALALlalalala papapapapapa", QDateTime::currentDateTime(), 0);
    todo1->setGeometry(500, 500, 430, 130);

    /*stackedWidget->setGeometry(0, 0, 1920, 1080);
    stackedWidget->setStyleSheet(QString("background-color:white;"));
    stackedWidget->addWidget(newTask);

    QCalendarWidget* dateInput = newTask->findChild<QCalendarWidget*>("dateEdit");

    dateInput->setGridVisible(true);
    dateInput->setSelectionMode(QCalendarWidget::SingleSelection);*/

    //stackedWidget->addWidget(todo1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

