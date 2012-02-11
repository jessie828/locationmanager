#include "location.h"


double Location::getAltitude() const
{
    return altitude;
}

double Location::getLatitude() const
{
    return latitude;
}

double Location::getLongitude() const
{
    return longitude;
}

QDateTime Location::getTime() const
{
    return time;
}

void Location::setAltitude(double altitude)
{
    this->altitude = altitude;
}

void Location::setLatitude(double latitude)
{
    this->latitude = latitude;
}

void Location::setLongitude(double longitude)
{
    this->longitude = longitude;
}

void Location::setTime(QDateTime time)
{
    this->time = time;
}

