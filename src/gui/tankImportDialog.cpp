#include "tankImportDialog.h"

#include <stdio.h>

TankImportDialog::TankImportDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
}

void TankImportDialog::accept()
{
    m_tank = new Tank();
    bool litersOK;
    bool priceOK;
    bool mileageOk;

    QDate date = dateEdit->date();

    m_tank->setDate(date);
    m_tank->setLiters(amountLineEdit->text().toDouble(&litersOK));
    m_tank->setPricePerLiter(priceLineEdit->text().toDouble(&priceOK));
    m_tank->setMileage(mileageLineEdit->text().toInt(&mileageOk));
    m_tank->setLocation(locationLineEdit->text());

    if(!litersOK)
    {
        QMessageBox::warning(0, QObject::tr("Input Error"), "The value for liters is not a valid number.\nPlease try again!");
    }
    else if(!priceOK)
    {
        QMessageBox::warning(0, QObject::tr("Input Error"), "The value for price per liter is not a valid number.\nPlease try again!");
    }
    else if(!mileageOk)
    {
        QMessageBox::warning(0, QObject::tr("Input Error"), "The value for mileage is not a valid number.\nPlease try again!");
    }
    else
    {
        Database::getInstance()->insert(m_tank);
        close();
    }
}

