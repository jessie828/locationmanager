#include "location.h"


int Location::getTripId() const
{
    return m_tripId;
}


double Location::getAltitude() const
{
    return m_altitude;
}

double Location::getLatitude() const
{
    return m_latitude;
}

double Location::getLongitude() const
{
    return m_longitude;
}

QDateTime Location::getTime() const
{
    return m_time;
}

void Location::setTripId(int tripId)
{
    m_tripId = tripId;
}


void Location::setAltitude(double altitude)
{
    m_altitude = altitude;
}

void Location::setLatitude(double latitude)
{
    m_latitude = latitude;
}

double Location::getDistance() const
{
    return m_distance;
}

double Location::getSpeedMps() const
{
    return m_speedMPS;
}

void Location::setDistance(double distance)
{
    m_distance = distance;
}

void Location::setSpeedMps(double speedMps)
{
    m_speedMPS = speedMps;
}

void Location::setLongitude(double longitude)
{
    m_longitude = longitude;
}

void Location::setTime(const QDateTime &time)
{
    m_time = time;
}

QString Location::toString() const
{
    QString dateFormat = QString("yyyy-MM-dd'T'hh:mm:ss'Z'");
    QString locationString;
    locationString = "Time: " + QString(m_time.toString(dateFormat)) +
        " altitude: " + QString::number(getAltitude()) +
        " latitude: " + QString::number(getLatitude()) +
        " longitude: " + QString::number(getLongitude());
    return locationString;
}

