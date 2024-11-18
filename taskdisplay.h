#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H

#include <QWidget>
#include <QString>
#include <QDateTime>
#include <QPainter>
#include <QStyleOption>

namespace Ui {
class TaskDisplay;
}

class TaskDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit TaskDisplay(QWidget *parent = nullptr);
    ~TaskDisplay();

    void setTitle(const QString &title, const QColor &color = Qt::blue);
    void setDescription(const QString &description, const QColor &color = Qt::gray);
    void setDueDate(const QDateTime &dueDate, const QColor &color = Qt::green);
    void setFlagColor(const QColor &color = Qt::blue);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::TaskDisplay *ui;

    QColor flagColor;
};

#endif // TASKDISPLAY_H
