/********************************************************************************
** Form generated from reading UI file 'taskdisplay.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDISPLAY_H
#define UI_TASKDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskDisplay
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *headerLayout;
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QLabel *dueDateLabel;

    void setupUi(QWidget *TaskDisplay)
    {
        if (TaskDisplay->objectName().isEmpty())
            TaskDisplay->setObjectName("TaskDisplay");
        TaskDisplay->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskDisplay->sizePolicy().hasHeightForWidth());
        TaskDisplay->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(TaskDisplay);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 301));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(15, 15, 15, 15);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(5, 5, 5, 5);
        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName("titleLabel");

        headerLayout->addWidget(titleLabel);


        mainLayout->addLayout(headerLayout);

        descriptionLabel = new QLabel(verticalLayoutWidget);
        descriptionLabel->setObjectName("descriptionLabel");
        descriptionLabel->setWordWrap(true);

        mainLayout->addWidget(descriptionLabel);

        dueDateLabel = new QLabel(verticalLayoutWidget);
        dueDateLabel->setObjectName("dueDateLabel");

        mainLayout->addWidget(dueDateLabel);


        retranslateUi(TaskDisplay);

        QMetaObject::connectSlotsByName(TaskDisplay);
    } // setupUi

    void retranslateUi(QWidget *TaskDisplay)
    {
        TaskDisplay->setWindowTitle(QCoreApplication::translate("TaskDisplay", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("TaskDisplay", "Title", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("TaskDisplay", "Description", nullptr));
        dueDateLabel->setText(QCoreApplication::translate("TaskDisplay", "Due Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDisplay: public Ui_TaskDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDISPLAY_H
