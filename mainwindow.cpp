#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    calendar = new CalendarWidget(this);
    calendar->setGeometry(0, 30, 1570, 1030);
    //stackedWidget = new QStackedWidget(this);
    //newTask = new newTaskWidget(this);
    //todo1 = new TaskWidget(this, "Bake a cake for mum", "Remember to buy cherries for it too! Her favourite cakes are vanilla ones. Also buy some apples, dad asked about them. And fridge is full of soup. Please finish it!", QDateTime::currentDateTime(), 0);
    //todo1->setGeometry(500, 500, 430, 145);

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

