#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QSpinBox>
#include <QLineEdit>

#include "trianglebutton.h"

class MySpinBox : public QSpinBox {
public:
    MySpinBox(QWidget *parent = nullptr) : QSpinBox(parent) {
        this->setMinimumWidth(165);
        this->getLineEdit()->setReadOnly(true);
        setFont(QFont("Bahnschrift", 35, QFont::DemiBold));
        /*this->setStyleSheet(R"(
        QSpinBox::up-button, QSpinBox::down-button {
            border: none;
        }
        QSpinBox::up-button:hover, QSpinBox::down-button:hover {
            background-color: lightgray;
        }
        )");*/
        this->setRange(2024, 2100);
        setButtonSymbols(QAbstractSpinBox::NoButtons);
        TriangleButton* yearUp = new TriangleButton(this, 0, Qt::black, 20, 20);
        TriangleButton* yearDown = new TriangleButton(this, 180, Qt::black, 20, 20);
        yearUp->setGeometry(115, 15, 20, 20);
        yearDown->setGeometry(141, 15, 20, 20);
        connect(yearUp, &QToolButton::clicked, this, &MySpinBox::yearIncrement);
        connect(yearDown, &QToolButton::clicked, this, &MySpinBox::yearDecrement);
    }

    QLineEdit* getLineEdit() {
        return lineEdit(); // Access protected lineEdit() method
    }

private slots:
    void yearIncrement()
    {
        blockSignals(true);
        setValue(this->value()+1);
        blockSignals(false);
        emit valueChanged(this->value());
    }

    void yearDecrement()
    {
        blockSignals(true);
        setValue(this->value()-1);
        blockSignals(false);
        emit valueChanged(this->value());
    }
};




#endif // MYSPINBOX_H
