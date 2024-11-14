#include "newtaskwidget.h"
#include "ui_newtaskwidget.h"

newTaskWidget::newTaskWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newTaskWidget)
{
    ui->setupUi(this);

    this->show();

    connect(ui->doneButton, &QPushButton::clicked, this, &newTaskWidget::onDoneButtonClicked);
    ui->nameInput->setEnabled(true);
    ui->nameInput->setReadOnly(false);
    ui->nameInput->setFocus();
    ui->nameInput->setStyleSheet("");
    ui->nameInput->setText("Hello World!");
}

newTaskWidget::~newTaskWidget()
{
    delete ui;
}

void newTaskWidget::onDoneButtonClicked()
{
    qDebug("Button Released!");
}
