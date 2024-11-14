#ifndef NEWTASKWIDGET_H
#define NEWTASKWIDGET_H

#include <QWidget>

namespace Ui {
class newTaskWidget;
}

class newTaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit newTaskWidget(QWidget *parent = nullptr);
    ~newTaskWidget();

private:
    Ui::newTaskWidget *ui;

private slots:
    void onDoneButtonClicked();
};

#endif // NEWTASKWIDGET_H
