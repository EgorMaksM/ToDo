#include "mainwindow.h"

#include "./ui_mainwindow.h"

#include <QTextEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    newTask = new newTaskWidget(this);

    stackedWidget->setGeometry(0, 35, 1000, 670);
    stackedWidget->addWidget(newTask);

    QWidget* nameInput = newTask->findChild<QTextEdit*>("nameInput");
    QWidget* descriptionInput = newTask->findChild<QTextEdit*>("descriptionInput");
    QPushButton* doneButton = newTask->findChild<QPushButton*>("doneButton");
}

MainWindow::~MainWindow()
{
    delete ui;
}
