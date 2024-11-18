#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);

    stackedWidget = new QStackedWidget(this);
    newTask = new newTaskWidget(this);
    todo1 = new TaskDisplay(this);

    stackedWidget->setGeometry(0, 35, 1300, 850);
    stackedWidget->addWidget(newTask);
    layout->addWidget(stackedWidget);

    QPlainTextEdit* nameInput = newTask->findChild<QPlainTextEdit*>("nameInput");
    QTextEdit* descriptionInput = newTask->findChild<QTextEdit*>("descriptionInput");
    QTimeEdit* timeInput = newTask->findChild<QTimeEdit*>("timeEdit");
    QCalendarWidget* dateInput = newTask->findChild<QCalendarWidget*>("dateEdit");
    QPushButton* doneButton = newTask->findChild<QPushButton*>("doneButton");

    dateInput->setGridVisible(true);
    dateInput->setSelectionMode(QCalendarWidget::SingleSelection);

    todo1->setTitle("Name", Qt::blue);
    todo1->setDescription("LALALALALlalalala papapapapapa", Qt::gray);
    todo1->setDueDate(QDateTime::currentDateTime(), Qt::green);
    todo1->setFlagColor(Qt::blue);

    stackedWidget->addWidget(todo1);
    stackedWidget->setCurrentWidget(todo1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
