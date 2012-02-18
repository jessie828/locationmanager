#include "location.h"


int Location::getTripId() const
{
    return tripId;
}


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

void Location::setTripId(int tripId)
{
    this->tripId = tripId;
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

QString Location::toString()
{
    QString dateFormat = QString("yyyy-MM-dd'T'hh:mm:ss'Z'");
    QString locationString;
    locationString = "Time: " + QString(time.toString(dateFormat)) +
        " altitude: " + QString::number(getAltitude()) +
        " latitude: " + QString::number(getLatitude()) +
        " longitude: " + QString::number(getLongitude());
    return locationString;
}

