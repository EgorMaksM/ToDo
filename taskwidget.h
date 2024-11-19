#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QFrame>
#include <QDateTime>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPainterPath>

namespace Ui {
class TaskWidget;
}

class TaskWidget : public QFrame
{
    Q_OBJECT

public:
    explicit TaskWidget(QWidget *parent = nullptr);
    ~TaskWidget();

    void setTitle(const QString &title, const QColor &color = Qt::blue);
    void setDescription(const QString &description, const QColor &color = Qt::gray);
    void setDueDate(const QDateTime &dueDate, const QColor &color = Qt::green);
    void setFlagColor(const QColor &color = Qt::blue);
    void setCornerRadii(const int &radius);
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::TaskWidget *ui;

    QColor flagColor;
    int cornerRadii = 20;
    QFont bahnschriftFont = QFont("Bahnschrift", 14);
};

#endif // TASKWIDGET_H
