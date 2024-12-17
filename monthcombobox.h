#ifndef MONTHCOMBOBOX_H
#define MONTHCOMBOBOX_H

#include <QComboBox>
#include <QObject>
#include <QFont>
#include <QStringList>
#include <QDateTime>
#include <QWheelEvent>
#include <QPropertyAnimation>
#include <QScrollBar>
#include <QAbstractItemView>
#include <QStyledItemDelegate>

class ColorDelegate : public QStyledItemDelegate {
public:
    ColorDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    QColor getColorForRow(int row) const {
        // Define colors for each row
        switch (row) {
        case 0: return QColor(59, 73, 255);    // Example colors
        case 1: return QColor(0, 24, 204);
        case 2: return QColor(227, 113, 255);
        case 3: return QColor(255, 60, 129);
        case 4: return QColor(197, 185, 1);
        case 5: return QColor(151, 207, 0);
        case 6: return QColor(0, 181, 8);
        case 7: return QColor(140, 179, 4);
        case 8: return QColor(218, 220, 27);
        case 9: return QColor(235, 137, 0);
        case 10: return QColor(168, 82, 5);
        case 11: return QColor(158, 73, 217);
        default: return QColor(Qt::black);
        }
    }

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // Set text color based on the index
        QColor textColor = getColorForRow(index.row());

        // Fix hover behavior: Ensure correct text color even when hovered
        if (opt.state.testFlag(QStyle::State_MouseOver) || opt.state.testFlag(QStyle::State_Active)) {
            opt.palette.setColor(QPalette::HighlightedText, textColor); // For hovered text
        }

        // Set normal text color
        opt.palette.setColor(QPalette::Text, textColor);
        opt.state &= ~QStyle::State_HasFocus;

        // Call base class to handle actual painting
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

class MonthComboBox : public QComboBox {
    Q_OBJECT

public:
    explicit MonthComboBox(QWidget* parent = nullptr);
    ~MonthComboBox() = default;

    void initialize();

signals:
    void monthChanged(int monthIndex);

private slots:
    void onMonthChanged(int index);

protected:
    void wheelEvent(QWheelEvent *event);
};

#endif // MONTHCOMBOBOX_H
