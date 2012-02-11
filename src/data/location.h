#ifndef LOCATION_H_
#define LOCATION_H_

#include <QDateTime>


class Location
{
private:
    QDateTime time;
    double altitude;
    double latitude;
    double longitude;

public:
    double getAltitude() const;
    double getLatitude() const;
    double getLongitude() const;
    QDateTime getTime() const;
    void setAltitude(double altitude);
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    void setTime(QDateTime time);
};

#endif /* LOCATION_H_ */
