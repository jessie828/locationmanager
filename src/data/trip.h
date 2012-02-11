#ifndef TRIP_H_
#define TRIP_H_

#include "location.h"

#include <QDateTime>
#include <QList>

class Trip
{
public:

private:
    QDateTime startDate;
    QDateTime stopDate;
    int duration;
    int distance;
    double avgSpeed;
    double maxSpeed;
    QList<Location> locations;

public:
    double getAvgSpeed() const;
    int getDistance() const;
    int getDuration() const;
    QList<Location> getLocations() const;
    double getMaxSpeed() const;
    QDateTime getStartDate() const;
    QDateTime getStopDate() const;
    void setAvgSpeed(double avgSpeed);
    void setDistance(int distance);
    void setDuration(int duration);
    void setLocations(QList<Location> locations);
    void setMaxSpeed(double maxSpeed);
    void setStartDate(QDateTime startDate);
    void setStopDate(QDateTime stopDate);
};

#endif /* TRIP_H_ */