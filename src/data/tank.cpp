#include "tank.h"


int Tank::getId() const
{
    return m_id;
}

QDate Tank::getDate() const
{
    return m_date;
}


double Tank::getLiters() const
{
    return m_liters;
}


QString Tank::getLocation() const
{
    return m_location;
}


int Tank::getMileage() const
{
    return m_mileage;
}


double Tank::getPricePerLiter() const
{
    return m_pricePerLiter;
}


void Tank::setId(int id)
{
    this->m_id = id;
}


void Tank::setDate(const QDate &date)
{
    this->m_date = date;
}


void Tank::setLiters(double liters)
{
    this->m_liters = liters;
}


void Tank::setLocation(const QString &location)
{
    this->m_location = location;
}


void Tank::setMileage(int mileage)
{
    this->m_mileage = mileage;
}


void Tank::setPricePerLiter(double pricePerLiter)
{
    this->m_pricePerLiter = pricePerLiter;
}


QString Tank::toString() const
{
    QString tankString;
    tankString = "date = " + QString(m_date.toString(QString("yyyy-MM-dd"))) +
        " liters = " + QString(QString::number(m_liters)) +
        " price per liter = " + QString::number(m_pricePerLiter) +
        " mileage = " + QString::number(m_mileage) +
        " location = " + m_location;
    return tankString;
}
