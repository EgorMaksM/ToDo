/********************************************************************************
** Form generated from reading UI file 'taskwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWIDGET_H
#define UI_TASKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskWidget
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

    void setupUi(QFrame *TaskWidget)
    {
        if (TaskWidget->objectName().isEmpty())
            TaskWidget->setObjectName("TaskWidget");
        TaskWidget->resize(430, 130);
        TaskWidget->setMaximumSize(QSize(430, 130));
        TaskWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        TaskWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(TaskWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, -5, 431, 141));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        flag = new QFrame(horizontalLayoutWidget);
        flag->setObjectName("flag");
        flag->setMaximumSize(QSize(20, 130));
        flag->setFrameShape(QFrame::Shape::StyledPanel);
        flag->setFrameShadow(QFrame::Shadow::Raised);

        mainLayout->addWidget(flag);

        contentLayout = new QVBoxLayout();
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(15, 15, 15, 15);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(15, 15, 15, 15);
        titleLabel = new QLabel(horizontalLayoutWidget);
        titleLabel->setObjectName("titleLabel");

        headerLayout->addWidget(titleLabel);


        contentLayout->addLayout(headerLayout);

        descriptionLabel = new QLabel(horizontalLayoutWidget);
        descriptionLabel->setObjectName("descriptionLabel");

        contentLayout->addWidget(descriptionLabel);

        dueDateLabel = new QLabel(horizontalLayoutWidget);
        dueDateLabel->setObjectName("dueDateLabel");

        contentLayout->addWidget(dueDateLabel);


        mainLayout->addLayout(contentLayout);


        retranslateUi(TaskWidget);

        QMetaObject::connectSlotsByName(TaskWidget);
    } // setupUi

    void retranslateUi(QFrame *TaskWidget)
    {
        TaskWidget->setWindowTitle(QCoreApplication::translate("TaskWidget", "Frame", nullptr));
        titleLabel->setText(QCoreApplication::translate("TaskWidget", "Name", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("TaskWidget", "Description", nullptr));
        dueDateLabel->setText(QCoreApplication::translate("TaskWidget", "Due Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskWidget: public Ui_TaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWIDGET_H
