#include "calendarwidget.h"
#include "ui_calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent, FileStream* filemgr)
    : QWidget(parent)
    , ui(new Ui::CalendarWidget)
    , FILEMGR(filemgr) {
    ui->setupUi(this);

    /*int loadedFontID = */QFontDatabase::addApplicationFont ( ":/digital-7.ttf" );
    //QFont Digital7("Digital-7", 15, QFont::Normal);

    currentDate = QDateTime::currentDateTime();

    mainLayout = new QVBoxLayout(this);

    setStyleSheet("background-color: white; color: black;"); //border: 2px solid black;");

    topLayout = new QVBoxLayout;
    monthYearLayout = new QHBoxLayout;
    weekLayout = new QHBoxLayout;

    topWidget = new QWidget(this);

    monthYearWidget = new QWidget(this);

    weekWidget = new QWidget(this);

    monthYearLayout->addStretch();

    // Month ComboBox and Year SpinBox (centered)
    monthComboBox = new MonthComboBox(this);
    monthYearLayout->addWidget(monthComboBox);

    yearSpinBox = new MySpinBox(this);
    yearSpinBox->setValue(QDate::currentDate().year());
    monthYearLayout->addWidget(yearSpinBox);

    // Add a flexible spacer to adjust space between yearSpinBox and PlusButton
    monthYearLayout->addStretch();

    // The PlusButton placed at the rightmost position
    newTask = new PlusButton(this);
    monthYearLayout->addWidget(newTask);

    prevWeekButton = new TriangleButton(this, -90, QColor("#2F4F4F"), 26, 18);
    nextWeekButton = new TriangleButton(this, 90, QColor("#2F4F4F"), 26, 18);

    weekLayout->addWidget(prevWeekButton);
    weekNumber = new QLabel(this);
    weekNumber->setStyleSheet("color: darkslategray;");
    weekNumber->setFont(QFont("Bahnschrift", 27, QFont::DemiBold));
    weekLayout->addWidget(weekNumber);
    weekLayout->addWidget(nextWeekButton);

    topWidget->setLayout(topLayout);
    monthYearWidget->setLayout(monthYearLayout);
    weekWidget->setLayout(weekLayout);
    topLayout->addWidget(monthYearWidget);
    topLayout->addWidget(weekWidget);

    //topLayout->setAlignment(monthYearWidget, Qt::AlignHCenter | Qt::AlignVCenter);
    topLayout->setAlignment(weekWidget, Qt::AlignHCenter | Qt::AlignVCenter);

    mainLayout->addWidget(topWidget);

    connect(monthComboBox, &QComboBox::currentIndexChanged, this, &CalendarWidget::onDateChanged);
    connect(yearSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &CalendarWidget::onDateChanged);
    connect(prevWeekButton, &QToolButton::clicked, this, &CalendarWidget::onPrevWeek);
    connect(nextWeekButton, &QToolButton::clicked, this, &CalendarWidget::onNextWeek);
    connect(newTask, &QAbstractButton::clicked, this, &CalendarWidget::onNewTask);

    // Create the fixed day header
    headerWidget = new QWidget(this);
    headerLayout = new QHBoxLayout(headerWidget);
    headerLayout->setContentsMargins(44, 0, 0, 0);  // Leave space for time labels
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

    // Add time labels on the left
    for (int hour = 0; hour <= 24; ++hour) {
        QLabel *timeLabel = new QLabel(QString("%1:00").arg(hour));
        timeLabel->setAlignment(Qt::AlignRight | Qt::AlignBottom);
        timeLabel->setContentsMargins(0, 0, 3, 0);
        timeLabel->setFont(QFont("Bahnschrift", 12, QFont::DemiBold));
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
    scrollContentLayout->setColumnMinimumWidth(0, 5);
    for (int day = 1; day <= 7; ++day) {
        scrollContentLayout->setColumnMinimumWidth(day, 209);
        scrollContentLayout->setColumnStretch(day, 1);
    }
    for (int hour = 0; hour <= 24; ++hour) {
        scrollContentLayout->setRowMinimumHeight(hour, 30);
    }

    scrollContentWidget->setLayout(scrollContentLayout);
    scrollArea->setWidget(scrollContentWidget);
    scrollArea->widget()->setContentsMargins(0, 0, 20, 0);

    // Add the scrollable area to the main layout
    mainLayout->addWidget(scrollArea);
    updateCalendar();
}

ProxyOverlay* CalendarWidget::AddTask(ToDo* task) {
    TaskWidget* instance = new TaskWidget(nullptr, task->Name, task->Description, task->DateTime, 0);
    ProxyOverlay* proxyOverlay = new ProxyOverlay(scrollContentWidget);
    proxyOverlay->setOverlayWidget(instance);
    FILEMGR->writeTask(task);
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

    scrollContentLayout->setRowMinimumHeight(hour, totalNumber>1 ? (totalNumber*35) : 30);
    int x = scrollContentLayout->cellRect(hour, day).left();
    int y = scrollContentLayout->cellRect(hour, day).top();
    for (int i = 0; i < totalNumber; i++) {
        ProxyOverlay* proxy = taskList[day-1][hour][i];
        proxy->setGeometry(x+2,
                           y + (i * 35) + 3,//y+(i*30)+((hour+i-(totalNumber*3)-7)*3),
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

    scrollContentLayout->setRowMinimumHeight(hour, totalNumber>1 ? (totalNumber*35) : 30);
    int x = scrollContentLayout->cellRect(hour, day).left();
    int y = scrollContentLayout->cellRect(hour, day).top();
    for (int i = 0; i < totalNumber; i++) {
        ProxyOverlay* proxy = taskList[day-1][hour][i];
        proxy->setGeometry(x+2,
                           y + (i * 35) + 3,//y+(i*30)+((hour+i-(totalNumber*3)-7)*3),
                           205,
                           28
                           );
        proxy->task->setEnabled(false);
        proxy->show();
    }
};

void CalendarWidget::updateCalendar() {
    // Clear the week header layout
    QLayoutItem* item;
    while ((item = headerLayout->takeAt(0)) != nullptr) {
        if (item->widget()) delete item->widget();
        delete item;
    }

    // Calculate the start of the current week based on currentDate
    int currentWeekNumber = currentDate.date().weekNumber();
    setWeek(currentWeekNumber);
    int year = currentDate.date().year();
    QDate firstDayOfWeek = QDate(year, 1, 1);
    firstDayOfWeek = firstDayOfWeek.addDays((currentWeekNumber - 1) * 7 - firstDayOfWeek.dayOfWeek() + 1);

    // Update the week header with day labels
    for (int i = 0; i < 7; ++i) {
        QDate currentDay = firstDayOfWeek.addDays(i);
        QLabel *dayLabel = new QLabel(currentDay.toString("ddd, d"));
        dayLabel->setAlignment(Qt::AlignCenter);
        dayLabel->setStyleSheet("font-weight: bold;");
        headerLayout->addWidget(dayLabel);
        headerLayout->setStretch(headerLayout->count() - 1, 1);
    }

    // Clear all existing task overlays
    std::vector<ProxyOverlay*> proxiesToDelete;
    for (int day = 0; day < taskList.size(); ++day) {
        for (int hour = 0; hour < taskList[day].size(); ++hour) {
            for (ProxyOverlay* proxy : taskList[day][hour]) {
                proxiesToDelete.push_back(proxy);
            }
        }
    }
    for (ProxyOverlay* proxy : proxiesToDelete) {
        DeleteTask(proxy); // Delete the task and overlay
    }

    // Reload tasks from FILEMGR that belong to the current week
    std::vector<ToDo*> allTasks = FILEMGR->readAllTasks();
    int weekNumber = currentDate.date().weekNumber();
    int monthNumber = currentDate.date().month();

    for (ToDo* task : allTasks) {
        int taskWeekNumber = task->DateTime.date().weekNumber();
        int taskMonthNumber = task->DateTime.date().month();
        if (taskWeekNumber == weekNumber && taskMonthNumber == monthNumber) {
            qDebug() << monthNumber << " : " << taskMonthNumber;
            AddTask(task);
        }
    }
}

void CalendarWidget::onDateChanged() {
    int month = monthComboBox->currentIndex() + 1;
    int year = yearSpinBox->value();

    currentDate.setDate(QDate(year, month, 1));

    updateCalendar();
}

void CalendarWidget::onNextWeek() {
    currentDate = currentDate.addDays(7);
    updateCalendar();
}

void CalendarWidget::onPrevWeek() {
    currentDate = currentDate.addDays(-7);
    updateCalendar();
}

void CalendarWidget::setWeek(int index) {
    weekNumber->setText("Week " + QString::number(index));
}

void CalendarWidget::onNewTask() {
    newTaskWidget *taskWindow = new newTaskWidget();

    // Create the dialog window to block interaction with the main window
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle("New Task");

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);  // Set the background color to white
    dialog->setPalette(palette);

    // Set the size of the dialog to match the size of newTaskWidget
    dialog->resize(taskWindow->size());  // Set the dialog size to the size of the widget

    // Make sure the window can't be resized or moved
    dialog->setFixedSize(taskWindow->size());  // Fix the size of the dialog

    // Set the dialog window to be modal, so it blocks interaction with the main window
    dialog->setModal(true);

    // Set the dialog to always appear above the main window
    dialog->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    // Set the dialog's content widget to be the newTaskWidget
    taskWindow->setParent(dialog);
    taskWindow->show();  // Show the newTaskWidget inside the dialog

    dialog->exec();
}

CalendarWidget::~CalendarWidget() {
    delete ui;
    std::vector<ToDo*> allTasks = FILEMGR->readAllTasks();

    // Debug output
    for (ToDo* task : allTasks) {
        qDebug() << "Deleting task:" << task->Name;
    }

    // Delete all tasks in memory
    FILEMGR->clearAllTasks(allTasks);

    // Clean up memory
    for (ToDo* task : allTasks) {
        delete task;
    }
}
