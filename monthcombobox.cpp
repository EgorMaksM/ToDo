#include "monthcombobox.h"

MonthComboBox::MonthComboBox(QWidget* parent)
    : QComboBox(parent) {
    initialize();
    connect(this, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MonthComboBox::onMonthChanged);
}

void MonthComboBox::initialize() {
    QStringList months = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
    this->addItems(months);
    this->setCurrentIndex(QDate::currentDate().month() - 1);
    this->setFont(QFont("Bahnschrift", 27, QFont::DemiBold));
    this->setMinimumWidth(this->fontMetrics().boundingRect("September").width() + 30);
    this->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    ColorDelegate* delegate = new ColorDelegate(this);
    setItemDelegate(delegate);

    connect(this, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index) {
        this->setStyleSheet(QString(R"(
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
        QListView::item {
            border: none;
            padding: 5px;
            outline: none;
            text-align: center;
        }
        QListView::item:hover {
            background: lightgrey;
            border: none;
            outline: none;
        }
        QListView::item:selected {
            background: lightgrey;
            /*color: black;*/
            border: none;
            outline: none;
        }
        QComboBox {
            text-align: center;
            color: %1;
        }
        QComboBox::item {
            text-align: center;
        }
        QAbstractItemView {
            text-align: center;
        }
    )").arg(delegate->getColorForRow(index).name()));
    });

    // Ensure the style sheet applies for the initial item
    this->setStyleSheet(QString(R"(
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
        QListView::item {
            border: none;
            padding: 5px;
            outline: none;
            text-align: center;
        }
        QListView::item:hover {
            background: lightgrey;
            border: none;
            outline: none;
        }
        QListView::item:selected {
            background: lightgrey;
            /*color: black;*/
            border: none;
            outline: none;
        }
        QComboBox {
            text-align: center;
            color: %1;
        }
        QComboBox::item {
            text-align: center;
        }
        QAbstractItemView {
            text-align: center;
        }
    )").arg(delegate->getColorForRow(this->currentIndex()).name()));
}


void MonthComboBox::wheelEvent(QWheelEvent *event) {
    QScrollBar *scrollBar = view()->verticalScrollBar();

    int delta = event->angleDelta().y();
    QPropertyAnimation *animation = new QPropertyAnimation(scrollBar, "value", this);
    animation->setDuration(qMin(400, 100 + abs(delta))); // Smooth animation duration
    animation->setStartValue(scrollBar->value());
    animation->setEndValue(scrollBar->value() - delta);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MonthComboBox::onMonthChanged(int index) {
    emit monthChanged(index + 1);
}
