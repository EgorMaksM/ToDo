#include "newtaskwidget.h"
#include "ui_newtaskwidget.h"

newTaskWidget::newTaskWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newTaskWidget)
{
    ui->setupUi(this);

    this->show();

    connect(ui->doneButton, &QPushButton::clicked, this, &newTaskWidget::onDoneButtonClicked);
}

newTaskWidget::~newTaskWidget()
{
    delete ui;
}

void newTaskWidget::onDoneButtonClicked()
{
    qDebug("Button Released!");
}
