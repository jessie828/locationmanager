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
    return avgSpeed;
}

int Trip::getDistance() const
{
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
    return maxSpeed;
}

QDateTime Trip::getStartDate() const
{
    return startDate;
}

QDateTime Trip::getStopDate() const
{
    return stopDate;
}

void Trip::setAvgSpeed(double avgSpeed)
{
    this->avgSpeed = avgSpeed;
}

void Trip::setDistance(int distance)
{
    this->distance = distance;
}

void Trip::setDuration(int duration)
{
    this->duration = duration;
}

void Trip::appendLocation(Location *location)
{
    this->locations.append(location);
}

void Trip::setMaxSpeed(double maxSpeed)
{
    this->maxSpeed = maxSpeed;
}

void Trip::setStartDate(QDateTime startDate)
{
    this->startDate = startDate;
}

void Trip::setStopDate(QDateTime stopDate)
{
    this->stopDate = stopDate;
}


QString Trip::toString()
{
    QString dateFormat = QString("yyyy-MM-dd'T'hh:mm:ss'Z'");
    QString locationString;
    locationString = "startDate = " + QString(startDate.toString(dateFormat)) +
        " stopDate = " + QString(stopDate.toString(dateFormat)) +
        " duration = " + QString::number(duration) +
        " distance = " + QString::number(distance) +
        " avgSpeed = " + QString::number(maxSpeed) +
        " location count = " + QString::number(locations.size());
    return locationString;
}

