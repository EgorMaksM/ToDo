#include "taskwidget.h"
#include "ui_taskwidget.h"
#include <qevent.h>

TaskWidget::TaskWidget(QWidget *parent,
                       const QString& title, const QColor &title_color,
                       const QString &description, const QColor &descr_color,
                       const QDateTime &dueDate, const QColor &dueDate_color,
                       const QColor &flagColor)
    : QFrame(parent)
    , ui(new Ui::TaskWidget)
    , flagColor(flagColor)
    , dueDate(dueDate)
{
    ui->setupUi(this);

    /* Main Components&Values Initialization */
    setTitle(title, title_color);
    setDescription(description, descr_color);
    ui->descriptionLabel->setVisible(false);
    setDueDate(dueDate, dueDate_color);

    /* Graphics Setup */
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("background-color: transparent;");
    ui->flag->setGeometry(0, 0, cornerRadii, height());

    /* Stylization */
    ui->titleLabel->setFont(titleFont);
    ui->descriptionLabel->setFont(descrFont);
    ui->dueDateLabel->setFont(dateFont);
}

TaskWidget::TaskWidget(QWidget *parent,
           const QString& title, const QString &description,
           const QDateTime &dueDate,
           const int paletteIndex)
    : QFrame(parent)
    , ui(new Ui::TaskWidget)
    , dueDate(dueDate)
{
    ui->setupUi(this);

    /* Main Components&Values Initialization */
    setTitle(title);
    setDescription(description);
    setDueDate(dueDate);
    setColorPalette(paletteIndex);

    ui->descriptionLabel->setVisible(false);

    /* Graphics Setup */
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("background-color: transparent;");
    ui->flag->setGeometry(0, 0, cornerRadii, height());

    /* Stylization */
    ui->titleLabel->setFont(titleFont);
    ui->descriptionLabel->setFont(descrFont);
    ui->dueDateLabel->setFont(dateFont);
};

TaskWidget::~TaskWidget()
{
    delete ui;
}

/* Change how "title" looks */
void TaskWidget::setTitle(const QString &title, const QColor &color)
{
    ui->titleLabel->setText(title);
    if (color != nullptr) ui->titleLabel->setStyleSheet(QString("color: %1;").arg(color.name()));
}
/* Change how "description" looks */
void TaskWidget::setDescription(const QString &description, const QColor &color)
{
    ui->descriptionLabel->setText(QString("• %1").arg(description));
    if (color != nullptr) ui->descriptionLabel->setStyleSheet(QString("color: %1;").arg(color.name()));
}

/* Change how "dueDate" looks */
void TaskWidget::setDueDate(const QDateTime &dueDate, const QColor &color)
{
    ui->dueDateLabel->setText(QString("◦ %1").arg(dueDate.toString("dd/MM/yyyy HH:mm")));
    if (color != nullptr) ui->dueDateLabel->setStyleSheet(QString("color: %1;").arg(color.name()));
}

/* Change how "flag" looks */
void TaskWidget::setFlagColor(const QColor &color)
{
    flagColor = color;
    update();
}

/* Set one of the premade Color Palettes */
void TaskWidget::setColorPalette(const int paletteIndex)
{
    QList<QColor>& palette = premadePalettes[paletteIndex];
    ui->titleLabel->setStyleSheet(QString("color: %1;").arg(palette[0].name()));
    ui->descriptionLabel->setStyleSheet(QString("color: %1;").arg(palette[1].name()));
    ui->dueDateLabel->setStyleSheet(QString("color: %1;").arg(palette[2].name()));
    setFlagColor(palette[3]);
}

/* Rounded corners logic & execution */
void TaskWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRectF widgetRect = QRectF(0, 0, width(), height());

    painter.setBrush(QColor(255, 255, 255));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(widgetRect, cornerRadii, cornerRadii);

    QRectF flagRect = QRectF(0, 0, cornerRadii, height());//ui->flag->geometry();
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

