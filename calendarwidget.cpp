#include "calendarwidget.h"
#include "ui_calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalendarWidget)
{
    ui->setupUi(this);

    mainLayout = new QVBoxLayout(this);

    // Create the fixed day header
    headerWidget = new QWidget(this);
    headerLayout = new QHBoxLayout(headerWidget);
    headerLayout->setContentsMargins(100, 0, 0, 0);  // Leave space for time labels
    headerLayout->setSpacing(0);

    QStringList days = {"Mon, 11", "Tue, 12", "Wed, 13", "Thu, 14", "Fri, 15", "Sat, 16", "Sun, 17"};
    for (const QString &day : days) {
        QLabel *dayLabel = new QLabel(day);
        dayLabel->setAlignment(Qt::AlignCenter);
        dayLabel->setStyleSheet("border-bottom: 1px solid gray; font-weight: bold;");
        headerLayout->addWidget(dayLabel);

        headerLayout->setStretch(headerLayout->count() - 1, 1);
    }
    headerWidget->setLayout(headerLayout);
    mainLayout->addWidget(headerWidget);

    // Create the scrollable area
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // Scrollable content
    scrollContentWidget = new QWidget();
    scrollContentLayout = new QGridLayout(scrollContentWidget);
    scrollContentLayout->setContentsMargins(0, 0, 0, 0);
    scrollContentLayout->setSpacing(0);

    // Add time labels on the left
    for (int hour = 1; hour <= 24; ++hour) {
        QLabel *timeLabel = new QLabel(QString("%1:00").arg(hour));
        timeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        timeLabel->setStyleSheet("padding-right: 5px;");
        scrollContentLayout->addWidget(timeLabel, hour - 1, 0);  // First column for time labels
    }

    // Add grid cells for tasks
    for (int hour = 1; hour <= 24; ++hour) {
        for (int day = 0; day < days.size(); ++day) {
            QLabel *cell = new QLabel;
            cell->setStyleSheet("border: 1px solid lightgray; border-collapse: collapse;");
            scrollContentLayout->addWidget(cell, hour - 1, day + 1);  // Offset day columns by 1
        }
    }

    scrollContentWidget->setLayout(scrollContentLayout);
    scrollArea->setWidget(scrollContentWidget);

    scrollContentLayout->setColumnStretch(0, 1);
    for (int day = 1; day <= 7; ++day) {
        scrollContentLayout->setColumnStretch(day, 2);
    }
    for (int day = 0; day <= 24; ++day) {
        scrollContentLayout->setRowMinimumHeight(day, 120);
    }

    // Add the scrollable area to the main layout
    mainLayout->addWidget(scrollArea);

    // Disable horizontal scrolling, enable vertical scrolling
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}
