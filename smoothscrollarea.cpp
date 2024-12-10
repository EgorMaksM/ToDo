#include "smoothscrollarea.h"

SmoothScrollArea::SmoothScrollArea(QWidget* parent) : QScrollArea(parent) {
    setWidgetResizable(true);

    scroller = QScroller::scroller(viewport());

    QScrollerProperties properties = scroller->scrollerProperties();
    properties.setScrollMetric(QScrollerProperties::DecelerationFactor, 0.2); // Adjust deceleration
    properties.setScrollMetric(QScrollerProperties::MaximumVelocity, 0.8);    // Adjust speed

    properties.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, QScrollerProperties::OvershootAlwaysOff);

    scroller->setScrollerProperties(properties);

    setStyleSheet(R"(
    QScrollBar:vertical {
        border: none;
        border-radius: 5px;
        background: #DFDFDF;
        width: 10px;
        margin: 2px 0px 0px 0px;
    }
    QScrollBar::handle:vertical {
        background-color: #B7B7B7;
        min-height: 20px;
        border-radius: 5px;
    }
    QScrollBar::handle:vertical:hover {
        background-color: #919191;
    }
    QScrollBar::add-line:vertical,
    QScrollBar::sub-line:vertical {
        height: 0px;
    }
    QScrollBar::add-page:vertical,
    QScrollBar::sub-page:vertical {
        background: none;
    }
)");
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void SmoothScrollArea::wheelEvent(QWheelEvent *event) {
    int delta = event->angleDelta().y();
    QPropertyAnimation *animation = new QPropertyAnimation(verticalScrollBar(), "value", this);
    //animation->setDuration(400); // Duration in ms
    animation->setDuration(qMin(400, 100 + abs(delta)));
    animation->setStartValue(verticalScrollBar()->value());
    animation->setEndValue(verticalScrollBar()->value() - delta);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
