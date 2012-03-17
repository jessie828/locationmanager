#include "tank.h"


QDate Tank::getDate() const
{
    return date;
}


double Tank::getLiters() const
{
    return liters;
}


QString Tank::getLocation() const
{
    return location;
}


int Tank::getMileage() const
{
    return mileage;
}


double Tank::getPricePerLiter() const
{
    return pricePerLiter;
}


void Tank::setDate(const QDate &date)
{
    this->date = date;
}


void Tank::setLiters(double liters)
{
    this->liters = liters;
}


void Tank::setLocation(QString location)
{
    this->location = location;
}


void Tank::setMileage(int mileage)
{
    this->mileage = mileage;
}


void Tank::setPricePerLiter(double pricePerLiter)
{
    this->pricePerLiter = pricePerLiter;
}


QString Tank::toString()
{
    QString tankString;
    tankString = "date = " + QString(date.toString(QString("yyyy-MM-dd"))) +
        " liters = " + QString(QString::number(liters)) +
        " price per liter = " + QString::number(pricePerLiter) +
        " mileage = " + QString::number(mileage) +
        " location = " + location;
    return tankString;
}
