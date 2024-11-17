/********************************************************************************
** Form generated from reading UI file 'newtaskwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTASKWIDGET_H
#define UI_NEWTASKWIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newTaskWidget
{
public:
    QLabel *nameInputLabel;
    QLabel *pageName;
    QPushButton *doneButton;
    QTextEdit *descriptionInput;
    QLabel *descriptionInputLabel;
    QTimeEdit *timeEdit;
    QCalendarWidget *dateEdit;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *nameInput;

    void setupUi(QWidget *newTaskWidget)
    {
        if (newTaskWidget->objectName().isEmpty())
            newTaskWidget->setObjectName("newTaskWidget");
        newTaskWidget->resize(1920, 1045);
        QFont font;
        font.setBold(false);
        newTaskWidget->setFont(font);
        newTaskWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        newTaskWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	padding: 12px;\n"
"    font-size: 40;\n"
"    font-weight: bold;\n"
"    text-align: center;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    background-color: #e6e6e6;\n"
"}\n"
"\n"
"QWidget {\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    height:fit-content;\n"
"    font-size: 18px;\n"
"	selection-background-color: #b3b3b3;\n"
"    selection-color: black;\n"
"    border: 2px solid;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTextEdit QScrollBar:vertical {\n"
"    background: transparent;\n"
"    width: 10px;\n"
"}\n"
"\n"
"QTextEdit QScrollBar::handle:vertical {\n"
"    background: #a3a3a3;\n"
"    border-radius: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QTextEdit QScrollBar::handle:vertical:hover {\n"
"    background: #7d7d7d;\n"
"}\n"
"\n"
"QTextEdit QScrollBar::add-line:vertical,\n"
"QTextEdit QScrollBar::sub-line:vertical {\n"
"    background: none;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"	height:fit-content;"
                        "\n"
"    font-size: 18px;\n"
"	selection-background-color: #b3b3b3;\n"
"    selection-color: black;\n"
"    border: 2px solid;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTimeEdit {\n"
"	selection-background-color: grey;\n"
"    selection-color: black;\n"
"    border: 1px solid #b3b3b3;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTimeEdit:focus {\n"
"	border: 1px solid #b3b3b3;\n"
"	background-color: #f0f0f0;\n"
"}\n"
"\n"
"QTimeEdit::up-button, QTimeEdit::down-button {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border: none;\n"
"    background: none;\n"
"}\n"
"\n"
"QCalendarWidget {\n"
"    border: 20px solid #409186;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"	selection-background-color: #b3b3b3;\n"
"    selection-color: black;\n"
"}\n"
"\n"
"QCalendarWidget QMenu {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #cccccc;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:focus {\n"
"    outline: none;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView::item:selected {\n"
"    background-"
                        "color: #7ba695;\n"
"    color: #13241d;\n"
"    border: 2px solid #2d4a3e;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView::item:hover {\n"
"    background-color: #93baa7;\n"
"    color: #13241d;\n"
"    border: 2px solid #466e5d;\n"
"	border-radius: 5px;\n"
"	font-weight: 50px;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView::item:selected:hover {\n"
"    background-color: #7ba695;\n"
"    color: #13241d;\n"
"    border: 2px solid #2d4a3e;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"	background-color: #409186;\n"
"    color: black;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton::menu-indicator {\n"
"    image: none;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView {\n"
"	background-color: #c3dbcf;\n"
"	selection-background-color: #7ba695;\n"
"    selection-color: #1d332b;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView::item {\n"
"	background-color: #c1e0d1;\n"
"	color: black;\n"
"	border: none;\n"
"}\n"
"\n"
"QCalendarWidget QWidget#q"
                        "t_calendar_navigationbar {\n"
"    background-color: #409186;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox {\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::down-button {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::up-button {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QCalendarWidget QComboBox QAbstractItemView {\n"
"    min-width: 100px; \n"
"    font-size: 14px; \n"
"}\n"
"\n"
"QCalendarWidget QComboBox::drop-down {\n"
"    width: 20px; \n"
"}\n"
"\n"
"QCalendarWidget QComboBox {\n"
"    font-size: 16px; \n"
"    min-width: 70px; \n"
"    padding: 2px; /* Add padding inside the box */\n"
"}"));
        nameInputLabel = new QLabel(newTaskWidget);
        nameInputLabel->setObjectName("nameInputLabel");
        nameInputLabel->setGeometry(QRect(0, 60, 151, 20));
        QFont font1;
        font1.setPointSize(11);
        nameInputLabel->setFont(font1);
        pageName = new QLabel(newTaskWidget);
        pageName->setObjectName("pageName");
        pageName->setGeometry(QRect(0, 0, 151, 41));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pageName->sizePolicy().hasHeightForWidth());
        pageName->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(18);
        font2.setBold(true);
        pageName->setFont(font2);
        pageName->setStyleSheet(QString::fromUtf8(""));
        doneButton = new QPushButton(newTaskWidget);
        doneButton->setObjectName("doneButton");
        doneButton->setGeometry(QRect(0, 700, 131, 81));
        QFont font3;
        font3.setPointSize(25);
        font3.setBold(true);
        doneButton->setFont(font3);
        doneButton->setStyleSheet(QString::fromUtf8("background-color: #e6e6e6;"));
        descriptionInput = new QTextEdit(newTaskWidget);
        descriptionInput->setObjectName("descriptionInput");
        descriptionInput->setGeometry(QRect(0, 140, 361, 111));
        descriptionInput->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        descriptionInput->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        descriptionInputLabel = new QLabel(newTaskWidget);
        descriptionInputLabel->setObjectName("descriptionInputLabel");
        descriptionInputLabel->setGeometry(QRect(0, 120, 161, 20));
        descriptionInputLabel->setFont(font1);
        timeEdit = new QTimeEdit(newTaskWidget);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(0, 300, 151, 51));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        timeEdit->setFont(font4);
        timeEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        timeEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timeEdit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        timeEdit->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToPreviousValue);
        timeEdit->setTimeSpec(Qt::TimeSpec::LocalTime);
        dateEdit = new QCalendarWidget(newTaskWidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(0, 410, 344, 211));
        QFont font5;
        font5.setPointSize(13);
        font5.setWeight(QFont::DemiBold);
        font5.setKerning(true);
        dateEdit->setFont(font5);
        dateEdit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        dateEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        dateEdit->setAutoFillBackground(false);
        dateEdit->setMinimumDate(QDate(1752, 9, 29));
        dateEdit->setFirstDayOfWeek(Qt::DayOfWeek::Monday);
        dateEdit->setGridVisible(true);
        dateEdit->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
        dateEdit->setNavigationBarVisible(true);
        dateEdit->setDateEditEnabled(true);
        label = new QLabel(newTaskWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 260, 81, 31));
        label->setFont(font1);
        label_2 = new QLabel(newTaskWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 370, 81, 31));
        label_2->setFont(font1);
        nameInput = new QPlainTextEdit(newTaskWidget);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(0, 80, 361, 31));
        nameInput->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        nameInput->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        nameInput->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);

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
        timeEdit->setDisplayFormat(QCoreApplication::translate("newTaskWidget", "h:mm", nullptr));
        label->setText(QCoreApplication::translate("newTaskWidget", "Set Time:", nullptr));
        label_2->setText(QCoreApplication::translate("newTaskWidget", "Set Date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newTaskWidget: public Ui_newTaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTASKWIDGET_H
