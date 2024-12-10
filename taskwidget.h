#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QFrame>
#include <QDateTime>
#include <QPainter>
#include <QPainterPath>
#include <QColor>
#include <QPropertyAnimation>

namespace Ui {
class TaskWidget;
}

class TaskWidget : public QFrame
{
    Q_OBJECT

public:
    Ui::TaskWidget *ui;

    QWidget* ParentOverlay;
    QDateTime dueDate;

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

    QColor flagColor;
    QFont bahnschriftFont = QFont("Bahnschrift");

    float relativeWidth = 1;
    float relativeHeight = 145 / 430;
    float cornerRadii = 4;//8 / 430;

    QFont titleFont = QFont("Bahnschrift", 10, QFont::Bold);
    QFont descrFont = QFont("Bahnschrift", 8, QFont::DemiBold);
    QFont dateFont = QFont("Bahnschrift", 9, QFont::DemiBold);
};

#endif // TASKWIDGET_H
