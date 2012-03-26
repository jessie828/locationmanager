#ifndef LOCATION_H_
#define LOCATION_H_

#include <QDateTime>

class Location
{
private:
    int m_tripId;
    QDateTime m_time;
    double m_altitude;
    double m_latitude;
    double m_longitude;

    double m_distance;
    double m_speedMPS;

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

    QString toString() const;
    double getDistance() const;
    double getSpeedMps() const;
    void setDistance(double distance);
    void setSpeedMps(double speedMps);
};

#endif /* LOCATION_H_ */
