#include "trip.h"



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

QList<Location> Trip::getLocations() const
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

void Trip::setLocations(QList<Location> locations)
{
    this->locations = locations;
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

