#ifndef PROXYOVERLAY_H
#define PROXYOVERLAY_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QChildEvent>

#include "taskwidget.h"
#include "ui_taskwidget.h"

class ProxyOverlay : public QWidget
{
    Q_OBJECT
public:
    explicit ProxyOverlay(QWidget *parent = nullptr)
        : QWidget(parent) {
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        setAttribute(Qt::WA_TranslucentBackground);
        setAttribute(Qt::WA_DeleteOnClose);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, 0);
        setLayout(layout);

        /* Drop-Shadow */
        shadow = new QGraphicsDropShadowEffect(this);
        shadow->setBlurRadius(15);
        shadow->setOffset(0.5, 0.5);
        shadow->setColor(QColor(0, 0, 0, 50));
        setGraphicsEffect(shadow);
    }

    void setOverlayWidget(TaskWidget *widget) {
        layout()->addWidget(widget);
        task = widget;
    }

    TaskWidget *task;
    QGraphicsDropShadowEffect *shadow;

    bool bResizing = false;
    QRect originalGeometry;
    QPropertyAnimation* animation;

    void enterEvent(QEnterEvent* event) override {
        if (bResizing) return;
        this->raise();
        originalGeometry = geometry();
        QRect newGeometry = QRect(originalGeometry.x(), originalGeometry.y(),
                                  originalGeometry.width(), 73);

        // Expand the widget
        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(200);
        animation->setStartValue(originalGeometry);
        animation->setEndValue(newGeometry);

        QPropertyAnimation *blurAnimation = new QPropertyAnimation(shadow, "blurRadius");
        blurAnimation->setDuration(200);
        blurAnimation->setStartValue(shadow->blurRadius());
        blurAnimation->setEndValue(18);
        blurAnimation->start(QAbstractAnimation::DeleteWhenStopped);

        QPropertyAnimation *colorAnimation = new QPropertyAnimation(shadow, "color");
        colorAnimation->setDuration(200);
        colorAnimation->setStartValue(shadow->color());
        colorAnimation->setEndValue(QColor(0, 0, 0, 200));
        colorAnimation->start(QAbstractAnimation::DeleteWhenStopped);

        connect(animation, &QPropertyAnimation::finished, this, &ProxyOverlay::onAnimationFinished);
        task->ui->mainLayout->setContentsMargins(0, 13, 0, 0);
        bResizing = true;
        animation->start(QAbstractAnimation::DeleteWhenStopped);
        task->ui->descriptionLabel->setVisible(true);
    }

    void leaveEvent(QEvent* event) override {
        if (bResizing) return;

        originalGeometry = geometry();
        QRect newGeometry = QRect(originalGeometry.x(), originalGeometry.y(),
                                  originalGeometry.width(), 30);

        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(300);
        animation->setStartValue(originalGeometry);
        animation->setEndValue(newGeometry);

        QPropertyAnimation *blurAnimation = new QPropertyAnimation(shadow, "blurRadius");
        blurAnimation->setDuration(200);
        blurAnimation->setStartValue(shadow->blurRadius());
        blurAnimation->setEndValue(15);
        blurAnimation->start(QAbstractAnimation::DeleteWhenStopped);

        QPropertyAnimation *colorAnimation = new QPropertyAnimation(shadow, "color");
        colorAnimation->setDuration(200);
        colorAnimation->setStartValue(shadow->color());
        colorAnimation->setEndValue(QColor(0, 0, 0, 50));
        colorAnimation->start(QAbstractAnimation::DeleteWhenStopped);

        connect(animation, &QPropertyAnimation::finished, this, &ProxyOverlay::onAnimationFinished);
        task->ui->mainLayout->setContentsMargins(0, 0, 0, 0);
        bResizing = true;
        animation->start(QAbstractAnimation::DeleteWhenStopped);
        task->ui->descriptionLabel->setVisible(false);
    }

    void childEvent(QChildEvent *event) override {
        if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
            event->ignore();
        }
    }

private slots:
    void onAnimationFinished() {
        bResizing = false;
    }
};

#endif // PROXYOVERLAY_H
