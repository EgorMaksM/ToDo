#include "newtaskwidget.h"
#include "ui_newtaskwidget.h"

newTaskWidget::newTaskWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newTaskWidget)
{
    ui->setupUi(this);
}

newTaskWidget::~newTaskWidget()
{
    delete ui;
}
