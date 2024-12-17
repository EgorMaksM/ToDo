#include "plusbutton.h"

PlusButton::PlusButton(QWidget *parent) : QAbstractButton(parent) {
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(60, 60); // Default minimum size

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(15);
    shadow->setOffset(3, 3);
    shadow->setColor(QColor(0, 0, 0, 150));
    setGraphicsEffect(shadow);
}

void PlusButton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw the rounded square
    QRect rect(5, 5, width() - 10, height() - 10);
    painter.setBrush(QColor(255, 255, 255));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 15, 15);

    QPen pen(Qt::black, 4);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
     // Outer margins for aesthetics
    painter.drawRoundedRect(rect, 15, 15);

    // Draw the plus sign
    int centerX = width() / 2;
    int centerY = height() / 2;
    int lineLength = qMin(width(), height()) / 2 - 20;

    // Vertical line
    painter.drawLine(centerX, centerY - lineLength / 2,
                     centerX, centerY + lineLength / 2);

    // Horizontal line
    painter.drawLine(centerX - lineLength / 2, centerY,
                     centerX + lineLength / 2, centerY);
}
