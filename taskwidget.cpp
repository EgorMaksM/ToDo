#include "taskwidget.h"
#include "ui_taskwidget.h"

TaskWidget::TaskWidget(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::TaskWidget)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("background-color: transparent;");

    ui->flag->setGeometry(0, 0, 20, 130);

    ui->titleLabel->setFont(bahnschriftFont);
    ui->descriptionLabel->setFont(bahnschriftFont);
    ui->dueDateLabel->setFont(bahnschriftFont);

    ui->titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
    ui->descriptionLabel->setStyleSheet("font-size: 14px; color: grey;");
    ui->dueDateLabel->setStyleSheet("font-size: 14px; color: green;");

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(15);
    shadow->setOffset(5, 5);
    shadow->setColor(QColor(0, 0, 0, 50));
    setGraphicsEffect(shadow);
    update();
}

TaskWidget::~TaskWidget()
{
    delete ui;
}

void TaskWidget::setTitle(const QString &title, const QColor &color)
{
    ui->titleLabel->setText(title);
    ui->titleLabel->setStyleSheet(QString("font-weight: bold; color: %1; font-size: 16px;").arg(color.name()));
}

void TaskWidget::setDescription(const QString &description, const QColor &color)
{
    ui->descriptionLabel->setText(description);
    ui->descriptionLabel->setStyleSheet(QString("color: %1; font-size: 14px;").arg(color.name()));
}

void TaskWidget::setDueDate(const QDateTime &dueDate, const QColor &color)
{
    ui->dueDateLabel->setText(QString("◦ %1").arg(dueDate.toString("dd/MM/yyyy HH:mm")));
    ui->dueDateLabel->setStyleSheet(QString("font-size: 14px; color: %1;").arg(color.name()));
}

void TaskWidget::setFlagColor(const QColor &color)
{
    flagColor = color;
    update();
    //ui->flag->setStyleSheet(QString("background-color: %1;").arg(color.name()));
}

void TaskWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRectF widgetRect = QRectF(0, 0, width(), height());

    painter.setBrush(QColor(255, 255, 255));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(widgetRect, cornerRadii, cornerRadii);

    QRectF flagRect = ui->flag->geometry();
    qDebug() << flagRect;
    int flagWidth = flagRect.width();
    int flagHeight = flagRect.height();

    QPainterPath flagPath;
    flagPath.moveTo(flagWidth, 0);  // Move to the top-right corner
    flagPath.lineTo(cornerRadii, 0); // Line to the top-left corner (rounded)

    // Top-left corner arc (first quarter-circle)
    flagPath.arcTo(QRectF(0, 0, 2 * cornerRadii, 2 * cornerRadii), 90, 90);

    // Left edge of flag (vertical line)
    flagPath.lineTo(0, flagHeight - cornerRadii);

    // Bottom-left corner arc (second quarter-circle)
    flagPath.arcTo(QRectF(0, flagHeight - 2 * cornerRadii, 2 * cornerRadii, 2 * cornerRadii), 180, 90);

    // Bottom edge of flag (horizontal line to bottom-right)
    flagPath.lineTo(flagWidth, flagHeight);

    // Right edge of flag (straight line to top-right)
    flagPath.lineTo(flagWidth, 0);
    flagPath.closeSubpath();

    painter.save();
    painter.setBrush(flagColor);
    painter.setPen(Qt::NoPen);
    painter.drawPath(flagPath);
    painter.restore();

    ui->flag->setAttribute(Qt::WA_OpaquePaintEvent, false);

    QFrame::paintEvent(event);
}
