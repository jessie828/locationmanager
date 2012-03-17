#ifndef TANK_H_
#define TANK_H_

#include <QDate>
#include <QString>

class Tank
{
private:
    QDate date;
    double liters;
    double pricePerLiter;
    int mileage;
    QString location;

public:
    QDate getDate() const;
    double getLiters() const;
    QString getLocation() const;
    int getMileage() const;
    double getPricePerLiter() const;
    void setDate(const QDate &date);
    void setLiters(double liters);
    void setLocation(QString location);
    void setMileage(int mileage);
    void setPricePerLiter(double pricePerLiter);

    QString toString();
};

#endif /* TANK_H_ */
