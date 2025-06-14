#include "datetime_dialog.h"
#include <QVBoxLayout>
#include <QDialogButtonBox>

DateTimeDialog::DateTimeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Wybierz datę i godzinę");
    QVBoxLayout *layout = new QVBoxLayout(this);

    dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm");
    dateTimeEdit->setCalendarPopup(true);
    layout->addWidget(dateTimeEdit);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

QDateTime DateTimeDialog::selectedDateTime() const {
    return dateTimeEdit->dateTime();
}
