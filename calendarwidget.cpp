#include "calendarwidget.h"
#include "ui_calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent, FileStream* filemgr)
    : QWidget(parent)
    , ui(new Ui::CalendarWidget)
    , FILEMGR(filemgr) {
    ui->setupUi(this);

    int loadedFontID = QFontDatabase::addApplicationFont ( ":/digital-7.ttf" );
    QFont Digital7("Digital-7", 15, QFont::Normal);

    mainLayout = new QVBoxLayout(this);

    setStyleSheet("background-color: white; color: black;");

    // Create the fixed day header
    headerWidget = new QWidget(this);
    headerLayout = new QHBoxLayout(headerWidget);
    headerLayout->setContentsMargins(55, 0, 0, 0);  // Leave space for time labels
    headerLayout->setSpacing(0);

    headerWidget->setLayout(headerLayout);
    mainLayout->addWidget(headerWidget);

    // Create the scrollable area
    scrollArea = new SmoothScrollArea(this);

    // Scrollable content
    scrollContentWidget = new QWidget();
    scrollContentLayout = new QGridLayout(scrollContentWidget);
    scrollContentLayout->setContentsMargins(0, 0, 0, 0);
    scrollContentLayout->setSpacing(0);

    SetWeek();
    qDebug() << "Made it so far!";
    //if (FILEMGR->readAllTasks().size() > 0) { FindWeek(FILEMGR->readAllTasks()); }

    qDebug() << "Made it so far!";
    // Add time labels on the left
    for (int hour = 0; hour <= 24; ++hour) {
        QLabel *timeLabel = new QLabel(QString("%1:00").arg(hour));
        timeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        timeLabel->setStyleSheet("padding-right: 2px;");
        timeLabel->setFont(Digital7);
        scrollContentLayout->addWidget(timeLabel, hour, 0);  // First column for time labels
    }

    // Add grid cells for tasks
    /*-------------------------------------------------------------------------------------------*/
    QLabel *cell = new QLabel;
    cell->setStyleSheet("border: 1px solid lightgray; border-left: 2px solid lightgray; border-top: 2px solid lightgray;");
    scrollContentLayout->addWidget(cell, 0, 1);
    for (int day = 1; day < 6; ++day) {
        QLabel *cell = new QLabel;
        cell->setStyleSheet("border: 1px solid lightgray; border-top: 2px solid lightgray;");
        scrollContentLayout->addWidget(cell, 0, day + 1);
    }
    QLabel *cell1 = new QLabel;
    cell1->setStyleSheet("border: 1px solid lightgray; border-right: 2px solid lightgray; border-top: 2px solid lightgray;");
    scrollContentLayout->addWidget(cell1, 0, 7);

    for (int hour = 1; hour <= 23; ++hour) {
        QLabel *cell = new QLabel;
        cell->setStyleSheet("border: 1px solid lightgray; border-left: 2px solid lightgray;");
        scrollContentLayout->addWidget(cell, hour, 1);
        for (int day = 1; day < 6; ++day) {
            QLabel *cell = new QLabel;
            cell->setStyleSheet("border: 1px solid lightgray;");
            scrollContentLayout->addWidget(cell, hour, day + 1);
        }
        QLabel *cell1 = new QLabel;
        cell1->setStyleSheet("border: 1px solid lightgray; border-right: 2px solid lightgray;");
        scrollContentLayout->addWidget(cell1, hour, 7);
    }

    QLabel *cell3 = new QLabel;
    cell3->setStyleSheet("border: 1px solid lightgray; border-left: 2px solid lightgray; border-bottom: 2px solid lightgray;");
    scrollContentLayout->addWidget(cell3, 24, 1);
    for (int day = 1; day < 6; ++day) {
        QLabel *cell = new QLabel;
        cell->setStyleSheet("border: 1px solid lightgray; border-bottom: 2px solid lightgray;");
        scrollContentLayout->addWidget(cell, 24, day + 1);
    }
    QLabel *cell4 = new QLabel;
    cell4->setStyleSheet("border: 1px solid lightgray; border-right: 2px solid lightgray; border-bottom: 2px solid lightgray;");
    scrollContentLayout->addWidget(cell4, 24, 7);

    for (int day = 1; day < 6; ++day) {
        QLabel *cell = new QLabel;
        cell->setStyleSheet("border: 1px solid lightgray; border-bottom: 2px solid lightgray;");
        scrollContentLayout->addWidget(cell, 24, day + 1);
    }
    /*-------------------------------------------------------------------------------------------*/

    scrollContentLayout->setColumnStretch(0, 0);
    scrollContentLayout->setColumnMinimumWidth(0, 30);
    for (int day = 1; day <= 7; ++day) {
        scrollContentLayout->setColumnMinimumWidth(day, 207);
        scrollContentLayout->setColumnStretch(day, 1);
    }
    for (int hour = 0; hour <= 24; ++hour) {
        scrollContentLayout->setRowMinimumHeight(hour, 30);
    }

    scrollContentWidget->setLayout(scrollContentLayout);
    scrollArea->setWidget(scrollContentWidget);
    scrollArea->widget()->setContentsMargins(0, 0, 10, 0);

    // Add the scrollable area to the main layout
    mainLayout->addWidget(scrollArea);
}

ProxyOverlay* CalendarWidget::AddTask(ToDo* task) {
    TaskWidget* instance = new TaskWidget(nullptr, task->Name, task->Description, task->DateTime, 0);
    ProxyOverlay* proxyOverlay = new ProxyOverlay(scrollContentWidget);
    proxyOverlay->setOverlayWidget(instance);
    int day = task->DateTime.date().dayOfWeek();
    int hour = task->DateTime.time().hour();

    int totalNumber = taskList[day-1][hour].length();

    if (totalNumber > 0) {
        bool bInserted = false;
        for (int i = 0; i < totalNumber; i++) {
            if (taskList[day-1][hour][i]->task->dueDate > task->DateTime) {
                taskList[day-1][hour].insert(i, proxyOverlay);
                bInserted = true;
            }
        }
        if (!bInserted) taskList[day-1][hour].push_back(proxyOverlay);
    }
    else taskList[day-1][hour].push_back(proxyOverlay);
    totalNumber = taskList[day-1][hour].length();

    scrollContentLayout->setRowMinimumHeight(hour, totalNumber>1 ? (totalNumber*30)+((totalNumber)*3) : 30);
    int x = scrollContentLayout->cellRect(hour, day).left();
    int y = scrollContentLayout->cellRect(hour, day).top();
    for (int i = 0; i < totalNumber; i++) {
        ProxyOverlay* proxy = taskList[day-1][hour][i];
        proxy->setGeometry(x+1,
                           y+(i*30)+((hour+i-(totalNumber*3)-7)*3),
                           205,
                           28
                            );
        proxy->task->setEnabled(false);
        proxy->show();
    }
    return proxyOverlay;
}

void CalendarWidget::DeleteTask(ProxyOverlay* proxy) {
    int day = proxy->task->dueDate.date().dayOfWeek();
    int hour = proxy->task->dueDate.time().hour();

    //taskList[day - 1][hour].detach();

    if (taskList[day-1][hour].removeOne(proxy)) {
        delete proxy->task;
        proxy->task = nullptr;
        delete proxy;
        proxy = nullptr;
    }
    int totalNumber = taskList[day-1][hour].length();

    scrollContentLayout->setRowMinimumHeight(hour, totalNumber>1 ? (totalNumber*30)+((totalNumber)*3) : 30);
    int x = scrollContentLayout->cellRect(hour, day).left();
    int y = scrollContentLayout->cellRect(hour, day).top();
    for (int i = 0; i < totalNumber; i++) {
        ProxyOverlay* proxy = taskList[day-1][hour][i];
        proxy->setGeometry(x+1,
                           y+(i*30)+((hour+i-(totalNumber*3)-7)*3),
                           205,
                           28
                           );
        proxy->task->setEnabled(false);
        proxy->show();
    }
};

void CalendarWidget::FindWeek(std::vector<ToDo*> tasks, int WeekIndex) {
    for (int i = 0; i < tasks.size(); i++) {
        QDate date = tasks[i]->DateTime.date();
        int year = date.year();
        if (date.weekNumber(&year) < WeekIndex) continue;
        else if (date.weekNumber(&year) > WeekIndex) break;
        else {
            AddTask(tasks[i]);
        }
    }
}

void CalendarWidget::SetWeek(int year, int weekNumber) {
    QLayoutItem* item;
    while ((item = headerLayout->takeAt(0)) != nullptr) {
        delete item;
    }
    QDate firstDayOfWeek = QDate(year, 1, 1);
    firstDayOfWeek = firstDayOfWeek.addDays((weekNumber - 1) * 7 - firstDayOfWeek.dayOfWeek() + 1);
    for (int i = 0; i < 7; ++i) {
        QDate currentDay = firstDayOfWeek.addDays(i);
        QLabel *dayLabel = new QLabel(currentDay.toString("ddd, d"));
        dayLabel->setAlignment(Qt::AlignCenter);
        dayLabel->setStyleSheet("font-weight: bold;");
        headerLayout->addWidget(dayLabel);

        headerLayout->setStretch(headerLayout->count() - 1, 1);
    }

    std::vector<ProxyOverlay*> proxiesToDelete;

    for (int i = 0; i < taskList.size(); i++) {
        for (int j = 0; j < taskList[i].size(); j++) {
            for (int k = 0; k < taskList[i][j].length(); k++)
                proxiesToDelete.push_back(taskList[i][j][k]);
        }
    }
    for (ProxyOverlay* proxy : proxiesToDelete) {
        DeleteTask(proxy); // Safely delete tasks after iterating
    }
}

CalendarWidget::~CalendarWidget() {
    delete ui;
}
