#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QFrame>
#include <QDateTime>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPainterPath>
#include <QColor>

namespace Ui {
class TaskWidget;
}

class TaskWidget : public QFrame
{
    Q_OBJECT

public:
    explicit TaskWidget(QWidget *parent = nullptr,
                        const QString& title="task_title", const QColor &title_color = Qt::black,
                        const QString &description="task_descr", const QColor &descr_color = Qt::gray,
                        const QDateTime &dueDate=QDateTime::currentDateTime(), const QColor &dueDate_color=Qt::red,
                        const QColor &flagColor=Qt::darkBlue);
    explicit TaskWidget(QWidget *parent = nullptr,
                        const QString& title="task_title", const QString &description="task_descr",
                        const QDateTime &dueDate=QDateTime::currentDateTime(),
                        const int paletteIndex=0);
    ~TaskWidget();

    void setTitle(const QString &title, const QColor &color = nullptr);
    void setDescription(const QString &description, const QColor &color = nullptr);
    void setDueDate(const QDateTime &dueDate, const QColor &color = nullptr);
    void setFlagColor(const QColor &color);
    void setColorPalette(const int paletteIndex);
    void paintEvent(QPaintEvent *event) override;

    QList<QColor> premadeColors = {QColor(29, 45, 138), QColor(103, 103, 103), QColor(13, 140, 19), QColor(49, 72, 210)};
    QList<QList<QColor>> premadePalettes = {
        {
            QColor(29, 45, 138), QColor(103, 103, 103), QColor(13, 140, 19), QColor(49, 72, 210)
        }
    };

private:
    Ui::TaskWidget *ui;

    QColor flagColor;
    int cornerRadii = 10;
    QFont bahnschriftFont = QFont("Bahnschrift", 14);
};

#endif // TASKWIDGET_H
