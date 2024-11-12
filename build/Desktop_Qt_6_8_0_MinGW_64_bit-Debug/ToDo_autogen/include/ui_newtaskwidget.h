/********************************************************************************
** Form generated from reading UI file 'newtaskwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTASKWIDGET_H
#define UI_NEWTASKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newTaskWidget
{
public:
    QLabel *nameInputLabel;
    QTextEdit *nameInput;
    QLabel *pageName;
    QPushButton *doneButton;
    QTextEdit *descriptionInput;
    QLabel *descriptionInputLabel;

    void setupUi(QWidget *newTaskWidget)
    {
        if (newTaskWidget->objectName().isEmpty())
            newTaskWidget->setObjectName("newTaskWidget");
        newTaskWidget->resize(1000, 700);
        nameInputLabel = new QLabel(newTaskWidget);
        nameInputLabel->setObjectName("nameInputLabel");
        nameInputLabel->setGeometry(QRect(30, 70, 151, 20));
        QFont font;
        font.setPointSize(11);
        nameInputLabel->setFont(font);
        nameInput = new QTextEdit(newTaskWidget);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(30, 90, 361, 31));
        pageName = new QLabel(newTaskWidget);
        pageName->setObjectName("pageName");
        pageName->setGeometry(QRect(30, 10, 151, 41));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pageName->sizePolicy().hasHeightForWidth());
        pageName->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(18);
        font1.setBold(true);
        pageName->setFont(font1);
        doneButton = new QPushButton(newTaskWidget);
        doneButton->setObjectName("doneButton");
        doneButton->setGeometry(QRect(30, 320, 131, 81));
        QFont font2;
        font2.setPointSize(25);
        font2.setBold(true);
        doneButton->setFont(font2);
        descriptionInput = new QTextEdit(newTaskWidget);
        descriptionInput->setObjectName("descriptionInput");
        descriptionInput->setGeometry(QRect(30, 150, 361, 111));
        descriptionInputLabel = new QLabel(newTaskWidget);
        descriptionInputLabel->setObjectName("descriptionInputLabel");
        descriptionInputLabel->setGeometry(QRect(30, 130, 161, 20));
        descriptionInputLabel->setFont(font);

        retranslateUi(newTaskWidget);

        QMetaObject::connectSlotsByName(newTaskWidget);
    } // setupUi

    void retranslateUi(QWidget *newTaskWidget)
    {
        newTaskWidget->setWindowTitle(QCoreApplication::translate("newTaskWidget", "Form", nullptr));
        nameInputLabel->setText(QCoreApplication::translate("newTaskWidget", "Name your ToDo:", nullptr));
        pageName->setText(QCoreApplication::translate("newTaskWidget", "New ToDo", nullptr));
        doneButton->setText(QCoreApplication::translate("newTaskWidget", "Done", nullptr));
        descriptionInputLabel->setText(QCoreApplication::translate("newTaskWidget", "Describe new ToDo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newTaskWidget: public Ui_newTaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTASKWIDGET_H
