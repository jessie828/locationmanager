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
    int m_id;
    QDateTime m_startDate;
    QDateTime m_stopDate;
    int m_duration;
    int m_distance;
    double m_avgSpeed;
    double m_maxSpeed;
    QList<Location*> m_locations;

public:
    Trip(int id);
    int getId() const;
    double calculateAvgSpeed() const;
    double getAvgSpeed() const;
    int calculateDistance() const;
    int getDistance() const;
    int getDuration() const;
    QList<Location*> getLocations() const;
    double calculateMaxSpeed() const;
    double getMaxSpeed() const;
    QDateTime getStartDate() const;
    QDateTime getStopDate() const;
    void setDistance(int distance);
    void calculateSpeed();
    void setDuration(int duration);
    void setStartDate(const QDateTime &startDate);
    void setStopDate(const QDateTime &stopDate);
    void appendLocation(Location *location);
    void calculateDistanceBetweenLocations();
    void setAvgSpeed(double avgSpeed);
    void setMaxSpeed(double maxSpeed);

    QString toString() const;
};

#endif /* TRIP_H_ */
