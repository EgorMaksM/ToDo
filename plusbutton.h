#ifndef PLUSBUTTON_H
#define PLUSBUTTON_H

#include <QAbstractButton>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>

class PlusButton : public QAbstractButton {
    Q_OBJECT

public:
    explicit PlusButton(QWidget *parent = nullptr);

protected:
    // Handle paint event to draw the button
    void paintEvent(QPaintEvent *event) override;
    QRectF originalGeometry;
    bool bResizing = false;
    QPropertyAnimation *animation;
    void enterEvent(QEnterEvent* event) override {
        if (bResizing) return;
        this->raise();
        originalGeometry = geometry();
        QRect newGeometry = QRect(originalGeometry.x(), originalGeometry.y(),
                                  65, 65);

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

        connect(animation, &QPropertyAnimation::finished, this, &PlusButton::onAnimationFinished);
        bResizing = true;
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }

    void leaveEvent(QEvent* event) override {
        if (bResizing) return;

        originalGeometry = geometry();
        QRect newGeometry = QRect(originalGeometry.x(), originalGeometry.y(),
                                  60, 60);

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

        connect(animation, &QPropertyAnimation::finished, this, &PlusButton::onAnimationFinished);
        bResizing = true;
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }

    // Handle mouse press event
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            setDown(true); // Change button state to pressed
        }
        QAbstractButton::mousePressEvent(event);
    }

    // Handle mouse release event
    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton && rect().contains(event->pos())) {
            setDown(false); // Reset button state
            emit clicked(); // Emit clicked signal
        }
        QAbstractButton::mouseReleaseEvent(event);
    }

    QGraphicsDropShadowEffect *shadow;

private slots:
    void onAnimationFinished() {
        bResizing = false;
    }
};

#endif // PLUSBUTTON_H
