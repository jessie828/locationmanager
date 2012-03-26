#include "trip.h"

Trip::Trip(int id)
{
    m_id = id;
}


int Trip::getId() const
{
    return m_id;
}


double Trip::calculateAvgSpeed() const
{
    int duration = getDuration();
    int distance = calculateDistance();
    return (distance / duration) * 3.6;
}

int Trip::calculateDistance() const
{
    int distance = 0;
    for(int i = 0; i < m_locations.size(); i++)
    {
        distance += m_locations.at(i)->getDistance();
    }
    return distance;
}

int Trip::getDuration() const
{
    return m_duration;
}

QList<Location*> Trip::getLocations() const
{
    return m_locations;
}

double Trip::calculateMaxSpeed() const
{
    double maxSpeed = 0;
    int size = m_locations.size();
    for(int i = 0; i < size; i++)
    {
        double speed = m_locations.at(i)->getSpeedMps();
        if(speed > maxSpeed)
        {
            maxSpeed = speed;
        }
    }

    return maxSpeed * 3.6;
}

QDateTime Trip::getStartDate() const
{
    return m_startDate;
}

QDateTime Trip::getStopDate() const
{
    return m_stopDate;
}


void Trip::calculateSpeed()
{
    int size = m_locations.size();
    int deltaTime = 0;
    unsigned int currentTime = 0, previousTime = 0;
    for(int i = 0; i < size; i++)
    {
        Location *loc = m_locations.at(i);
        QDateTime current = loc->getTime();
        currentTime = current.toTime_t();
        deltaTime = currentTime - previousTime;
        loc->setSpeedMps(Util::speedInMps(loc->getDistance(), deltaTime));
        if(i == 0)
        {
            loc->setSpeedMps(0);
        }
        previousTime = currentTime;
    }
}


void Trip::setDistance(int distance)
{
    m_distance = distance;
}


void Trip::calculateDistanceBetweenLocations()
{
    Coordinate current, previous;
    int size = m_locations.size();
    for(int i = 0; i < size; i++)
    {
        Location *currentLoc = m_locations.at(i);
        current.lat = currentLoc->getLatitude();
        current.lon = currentLoc->getLongitude();
        currentLoc->setDistance(Util::distanceInMeters(previous, current));
        if(i == 0)
        {
            currentLoc->setDistance(0);
        }
        previous = current;
    }
}

void Trip::setDuration(int duration)
{
    m_duration = duration;
}

void Trip::appendLocation(Location *location)
{
    m_locations.append(location);
}


void Trip::setStartDate(const QDateTime &startDate)
{
    m_startDate = startDate;
}

void Trip::setStopDate(const QDateTime &stopDate)
{
    m_stopDate = stopDate;
}


void Trip::setAvgSpeed(double avgSpeed)
{
    m_avgSpeed = avgSpeed;
}


void Trip::setMaxSpeed(double maxSpeed)
{
    m_maxSpeed = maxSpeed;
}


double Trip::getAvgSpeed() const
{
    return m_avgSpeed;
}


double Trip::getMaxSpeed() const
{
    return m_maxSpeed;
}


int Trip::getDistance() const
{
    return m_distance;
}


QString Trip::toString() const
{
    QString dateFormat = QString("yyyy-MM-dd hh:mm:ss");
    QString tripString;
    tripString = "tripId = " + QString::number(m_id) +
        " startDate = " + QString(m_startDate.toString(dateFormat)) +
        " stopDate = " + QString(m_stopDate.toString(dateFormat)) +
        " duration = " + QString::number(m_duration) +
        " distance = " + QString::number(m_distance) +
        " avgSpeed = " + QString::number(m_avgSpeed) +
        " maxSpeed = " + QString::number(m_maxSpeed) +
        " location count = " + QString::number(m_locations.size());
    return tripString;
}

