#include "taskdisplay.h"
#include "ui_taskdisplay.h"

TaskDisplay::TaskDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TaskDisplay)
{
    ui->setupUi(this);

    ui->titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
    ui->descriptionLabel->setStyleSheet("font-size: 14px; color: grey;");
    ui->dueDateLabel->setStyleSheet("font-size: 14px; color: green;");
}

TaskDisplay::~TaskDisplay()
{
    delete ui;
}

void TaskDisplay::setTitle(const QString &title, const QColor &color)
{
    ui->titleLabel->setText(title);
    ui->titleLabel->setStyleSheet(QString("font-weight: bold; color: %1; font-size: 16px;").arg(color.name()));
}

void TaskDisplay::setDescription(const QString &description, const QColor &color)
{
    ui->descriptionLabel->setText(description);
    ui->descriptionLabel->setStyleSheet(QString("color: %1; font-size: 14px;").arg(color.name()));
}

void TaskDisplay::setDueDate(const QDateTime &dueDate, const QColor &color) {
    ui->dueDateLabel->setText(QString("◦ %1").arg(dueDate.toString("dd/MM/yyyy HH:mm")));
    ui->dueDateLabel->setStyleSheet(QString("font-size: 14px; color: %1;").arg(color.name()));
}

void TaskDisplay::setFlagColor(const QColor &color) {
    flagColor = color;
    update();
}

void TaskDisplay::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect rect(0, 0, 10, height());
    painter.setBrush(flagColor);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect);

    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
