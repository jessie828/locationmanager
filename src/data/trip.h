#ifndef TRIP_H_
#define TRIP_H_

#include "location.h"
#include "util.h"

#include <stdio.h>

#include <QDateTime>
#include <QList>

class Trip
{
private:
    int id;
    QDateTime startDate;
    QDateTime stopDate;
    int duration;
    int distance;
    double avgSpeed;
    double maxSpeed;
    QList<Location*> locations;

public:
    Trip(int id);
    int getId() const;
    double getAvgSpeed() const;
    int getDistance() const;
    int getDuration() const;
    QList<Location*> getLocations() const;
    double getMaxSpeed() const;
    QDateTime getStartDate() const;
    QDateTime getStopDate() const;
    void setDistance(int distance);
    void calculateSpeed();
    void setDuration(int duration);
    void setStartDate(QDateTime startDate);
    void setStopDate(QDateTime stopDate);
    void appendLocation(Location *location);
    void calculateDistanceBetweenLocations();

    QString toString();
};

#endif /* TRIP_H_ */
