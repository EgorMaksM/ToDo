#ifndef TRIANGLEBUTTON_H
#define TRIANGLEBUTTON_H

#include <QToolButton>
#include <QPainter>
#include <QPainterPath>
#include <QBrush>

class TriangleButton : public QToolButton
{
    Q_OBJECT

public:
    explicit TriangleButton(QWidget *parent = nullptr, int angle = 0, QColor color = Qt::gray, int width = 26, int height = 26);

protected:
    void paintEvent(QPaintEvent *event) override;
    int m_angle;
    int m_cornerRadius;
    QColor color;
};


#endif // TRIANGLEBUTTON_H
