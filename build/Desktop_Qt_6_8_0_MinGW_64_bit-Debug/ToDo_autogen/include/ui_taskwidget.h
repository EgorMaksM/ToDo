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
        TaskWidget->setEnabled(false);
        TaskWidget->resize(200, 73);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskWidget->sizePolicy().hasHeightForWidth());
        TaskWidget->setSizePolicy(sizePolicy);
        TaskWidget->setMaximumSize(QSize(16777215, 16777215));
        TaskWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        TaskWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(TaskWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, -5, 201, 81));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout->setSpacing(2);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        flag = new QFrame(horizontalLayoutWidget);
        flag->setObjectName("flag");
        flag->setEnabled(false);
        flag->setMaximumSize(QSize(20, 145));
        flag->setFrameShape(QFrame::Shape::StyledPanel);
        flag->setFrameShadow(QFrame::Shadow::Raised);

        mainLayout->addWidget(flag);

        contentLayout = new QVBoxLayout();
        contentLayout->setSpacing(0);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 3);
        headerLayout = new QHBoxLayout();
        headerLayout->setSpacing(0);
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(horizontalLayoutWidget);
        titleLabel->setObjectName("titleLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy1);
        titleLabel->setMargin(-1);

        headerLayout->addWidget(titleLabel);


        contentLayout->addLayout(headerLayout);

        descriptionLabel = new QLabel(horizontalLayoutWidget);
        descriptionLabel->setObjectName("descriptionLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(descriptionLabel->sizePolicy().hasHeightForWidth());
        descriptionLabel->setSizePolicy(sizePolicy2);
        descriptionLabel->setWordWrap(true);

        contentLayout->addWidget(descriptionLabel);

        dueDateLabel = new QLabel(horizontalLayoutWidget);
        dueDateLabel->setObjectName("dueDateLabel");
        dueDateLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        dueDateLabel->setMargin(3);

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
