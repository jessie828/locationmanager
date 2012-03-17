#include "trip.h"

Trip::Trip(int id)
{
    this->id = id;
}


int Trip::getId() const
{
    return id;
}


double Trip::getAvgSpeed() const
{
    int duration = getDuration();
    int distance = getDistance();
    return (distance / duration) * 3.6;
}

int Trip::getDistance() const
{
    int distance = 0;
    for(int i = 0; i < locations.size(); i++)
    {
        distance += locations.at(i)->getDistance();
    }
    return distance;
}

int Trip::getDuration() const
{
    return duration;
}

QList<Location*> Trip::getLocations() const
{
    return locations;
}

double Trip::getMaxSpeed() const
{
    double maxSpeed = 0;
    int size = locations.size();
    for(int i = 0; i < size; i++)
    {
        double speed = locations.at(i)->getSpeedMps();
        if(speed > maxSpeed)
        {
            maxSpeed = speed;
        }
    }

    return maxSpeed * 3.6;
}

QDateTime Trip::getStartDate() const
{
    return startDate;
}

QDateTime Trip::getStopDate() const
{
    return stopDate;
}


void Trip::calculateSpeed()
{
    int size = locations.size();
    int deltaTime = 0;
    unsigned int currentTime = 0, previousTime = 0;
    for(int i = 0; i < size; i++)
    {
        Location *loc = locations.at(i);
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
    this->distance = distance;
}


void Trip::calculateDistanceBetweenLocations()
{
    Coordinate current, previous;
    int size = locations.size();
    for(int i = 0; i < size; i++)
    {
        Location *currentLoc = locations.at(i);
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
    this->duration = duration;
}

void Trip::appendLocation(Location *location)
{
    this->locations.append(location);
}


void Trip::setStartDate(QDateTime startDate)
{
    this->startDate = startDate;
}

void Trip::setStopDate(QDateTime stopDate)
{
    this->stopDate = stopDate;
}


void Trip::setAvgSpeed(double avgSpeed)
{
    this->avgSpeed = avgSpeed;
}


void Trip::setMaxSpeed(double maxSpeed)
{
    this->maxSpeed = maxSpeed;
}


QString Trip::toString()
{
    QString dateFormat = QString("yyyy-MM-dd'T'hh:mm:ss'Z'");
    QString tripString;
    tripString = "startDate = " + QString(startDate.toString(dateFormat)) +
        " stopDate = " + QString(stopDate.toString(dateFormat)) +
        " duration = " + QString::number(duration) +
        " distance = " + QString::number(distance) +
        " avgSpeed = " + QString::number(maxSpeed) +
        " location count = " + QString::number(locations.size());
    return tripString;
}

