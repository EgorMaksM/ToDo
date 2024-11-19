#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //stackedWidget = new QStackedWidget(this);
    //newTask = new newTaskWidget(this);
    todo1 = new TaskWidget(this);
    todo1->setGeometry(500, 500, 430, 130);

    /*stackedWidget->setGeometry(0, 0, 1920, 1080);
    stackedWidget->setStyleSheet(QString("background-color:white;"));
    stackedWidget->addWidget(newTask);

    QCalendarWidget* dateInput = newTask->findChild<QCalendarWidget*>("dateEdit");

    dateInput->setGridVisible(true);
    dateInput->setSelectionMode(QCalendarWidget::SingleSelection);*/

    todo1->setTitle("Name", Qt::blue);
    todo1->setDescription("LALALALALlalalala papapapapapa", Qt::gray);
    todo1->setDueDate(QDateTime::currentDateTime(), Qt::green);
    todo1->setFlagColor(Qt::blue);

    //todo1->setStyleSheet(QString("background-color:white;"));
    todo1->setFlagColor(Qt::blue);
    todo1->setGeometry(500, 500, 430, 130);

    //stackedWidget->addWidget(todo1);

    //stackedWidget->setCurrentWidget(todo1);
    qDebug() << "Todo1 geometry:" << todo1->geometry();
    qDebug() << "Todo1 visible:" << todo1->isVisible();
    qDebug() << "Todo1's parent:" << todo1->parent();
}

MainWindow::~MainWindow()
{
    delete ui;
}
