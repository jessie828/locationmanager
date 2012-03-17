#ifndef LOCATION_H_
#define LOCATION_H_

#include <QDateTime>

class Location
{
private:
    int tripId;
    QDateTime time;
    double altitude;
    double latitude;
    double longitude;

    double distance;
    double speedMPS;

public:
    int getTripId() const;
    double getAltitude() const;
    double getLatitude() const;
    double getLongitude() const;
    QDateTime getTime() const;
    void setTripId(int tripId);
    void setAltitude(double altitude);
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    void setTime(const QDateTime &time);

    QString toString();
    double getDistance() const;
    double getSpeedMps() const;
    void setDistance(double distance);
    void setSpeedMps(double speedMps);
};

#endif /* LOCATION_H_ */
