#include "trianglebutton.h"

TriangleButton::TriangleButton(QWidget *parent, int angle, QColor color, int width, int height)
    : QToolButton(parent), m_angle(angle), color(color)
{
    setFixedSize(width, height);  // Set fixed size for button
    setToolButtonStyle(Qt::ToolButtonIconOnly);  // Ensure it's just an icon button (no text)
}

void TriangleButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Translate to the center for rotation
    painter.translate(width() / 2.0, height() / 2.0);
    painter.rotate(m_angle);

    // Triangle size
    const qreal size = 26 / 2.0;  // You can adjust the size as needed

    // Define triangle vertices (top, bottom-left, bottom-right)
    QPointF topPoint(0, -(height()/2));
    QPointF bottomRightPoint(width()/2, height()/2);
    QPointF bottomLeftPoint(-(width()/2), height()/2);

    // Create a polygon (triangle)
    QPolygonF triangle;
    triangle << topPoint << bottomLeftPoint << bottomRightPoint;

    // Set brush and draw the polygon
    painter.setBrush(color);
    painter.setPen(Qt::NoPen);
    painter.drawPolygon(triangle);
}
