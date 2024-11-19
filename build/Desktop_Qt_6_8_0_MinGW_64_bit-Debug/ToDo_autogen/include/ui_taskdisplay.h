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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskDisplay
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainLayout;
    QFrame *flag;
    QVBoxLayout *contentLayout;
    QHBoxLayout *headerLayout;
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QLabel *dueDateLabel;

    void setupUi(QWidget *TaskDisplay)
    {
        if (TaskDisplay->objectName().isEmpty())
            TaskDisplay->setObjectName("TaskDisplay");
        TaskDisplay->resize(430, 130);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskDisplay->sizePolicy().hasHeightForWidth());
        TaskDisplay->setSizePolicy(sizePolicy);
        TaskDisplay->setMaximumSize(QSize(430, 130));
        TaskDisplay->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: white;\n"
"}\n"
"\n"
"QFrame #flag {\n"
"	background-color: blue;\n"
"}"));
        horizontalLayoutWidget = new QWidget(TaskDisplay);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 432, 134));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout->setSpacing(5);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        flag = new QFrame(horizontalLayoutWidget);
        flag->setObjectName("flag");
        sizePolicy.setHeightForWidth(flag->sizePolicy().hasHeightForWidth());
        flag->setSizePolicy(sizePolicy);
        flag->setMaximumSize(QSize(10, 16777215));
        flag->setFrameShape(QFrame::Shape::StyledPanel);
        flag->setFrameShadow(QFrame::Shadow::Raised);

        mainLayout->addWidget(flag);

        contentLayout = new QVBoxLayout();
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(5, 5, 5, 5);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(5, 5, 5, 5);
        titleLabel = new QLabel(horizontalLayoutWidget);
        titleLabel->setObjectName("titleLabel");

        headerLayout->addWidget(titleLabel);


        contentLayout->addLayout(headerLayout);

        descriptionLabel = new QLabel(horizontalLayoutWidget);
        descriptionLabel->setObjectName("descriptionLabel");
        sizePolicy.setHeightForWidth(descriptionLabel->sizePolicy().hasHeightForWidth());
        descriptionLabel->setSizePolicy(sizePolicy);
        descriptionLabel->setMinimumSize(QSize(371, 0));
        descriptionLabel->setWordWrap(true);

        contentLayout->addWidget(descriptionLabel);

        dueDateLabel = new QLabel(horizontalLayoutWidget);
        dueDateLabel->setObjectName("dueDateLabel");
        dueDateLabel->setEnabled(true);

        contentLayout->addWidget(dueDateLabel);


        mainLayout->addLayout(contentLayout);


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
