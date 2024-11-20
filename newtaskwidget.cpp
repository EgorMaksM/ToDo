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

    onTimeChanged(QTime::currentTime());
}

newTaskWidget::~newTaskWidget()
{
    delete ui;
}

/* Check new time's correctness */
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

/* Check new date's correctness */
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

/* Executed when "Done" button is clicked */
void newTaskWidget::onDoneButtonClicked()
{
    ToDo newTask(ui->nameInput->toPlainText(), ui->descriptionInput->toPlainText(), selectedDateTime);
    qDebug() << "New Name: " << newTask.Name;
    qDebug() << "New Description: " << newTask.Description;
    qDebug() << "New DateTime: " << newTask.DateTime;
}
