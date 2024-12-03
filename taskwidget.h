#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QFrame>
#include <QDateTime>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPainterPath>
#include <QColor>
#include <QSizeGrip>

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
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    QList<QColor> premadeColors = {QColor(29, 45, 138), QColor(103, 103, 103), QColor(13, 140, 19), QColor(49, 72, 210)};
    QList<QList<QColor>> premadePalettes = {
        {
            QColor(29, 45, 138), QColor(103, 103, 103), QColor(13, 140, 19), QColor(49, 72, 210)
        }
    };

private:
    Ui::TaskWidget *ui;

    QColor flagColor;
    QFont bahnschriftFont = QFont("Bahnschrift");

    float relativeWidth = 1;
    float relativeHeight = 145 / 430;
    float cornerRadii = 0;//8 / 430;

    QFont titleFont = QFont("Bahnschrift", 17, QFont::Bold);
    QFont descrFont = QFont("Bahnschrift", 13, QFont::DemiBold);
    QFont dateFont = QFont("Bahnschrift", 18, QFont::DemiBold);

    const float relationsMatrix[5] = {0.3372, 0.0186, 0.0395, 0.0302, 0.0418};
};

#endif // TASKWIDGET_H
