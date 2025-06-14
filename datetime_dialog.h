#ifndef DATETIME_DIALOG_H
#define DATETIME_DIALOG_H
#include <QDialog>
#include <QDateTimeEdit>

class DateTimeDialog : public QDialog {
    Q_OBJECT
public:
    explicit DateTimeDialog(QWidget *parent = nullptr);

    QDateTime selectedDateTime() const;

private:
    QDateTimeEdit *dateTimeEdit;
};

#endif
