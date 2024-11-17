#include "newtaskwidget.h"
#include "ui_newtaskwidget.h"

newTaskWidget::newTaskWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newTaskWidget)
{
    ui->setupUi(this);

    this->show();

    connect(ui->doneButton, &QPushButton::clicked, this, &newTaskWidget::onDoneButtonClicked);
    connect(ui->timeEdit, &QTimeEdit::timeChanged, this, &newTaskWidget::onTimeChanged);
    connect(ui->dateEdit, &QCalendarWidget::selectionChanged, this, &newTaskWidget::onDateChanged);
}

newTaskWidget::~newTaskWidget()
{
    delete ui;
}

void newTaskWidget::onTimeChanged(const QTime& newTime)
{
    QDateTime currDateTime = QDateTime::currentDateTime();
    selectedDateTime.setTime(newTime);
    if (selectedDateTime < currDateTime)
    {
        selectedDateTime = currDateTime;
        ui->timeEdit->setDateTime(selectedDateTime);
        ui->dateEdit->setSelectedDate(selectedDateTime.date());
    }
}

void newTaskWidget::onDateChanged()
{
    QDate newDate = ui->dateEdit->selectedDate();
    QDate currDate = QDate::currentDate();
    selectedDateTime.setDate(newDate);
    if (selectedDateTime.date() < currDate)
    {
        selectedDateTime.setDate(currDate);
        ui->timeEdit->setDateTime(selectedDateTime);
        ui->dateEdit->setSelectedDate(selectedDateTime.date());
    }
}

void newTaskWidget::onDoneButtonClicked()
{
    ToDo newTask();
}
