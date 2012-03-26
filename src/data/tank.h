#ifndef TANK_H_
#define TANK_H_

#include <QDate>
#include <QString>

class Tank
{
private:
    int m_id;
    QDate m_date;
    double m_liters;
    double m_pricePerLiter;
    int m_mileage;
    QString m_location;

public:
    int getId() const;
    QDate getDate() const;
    double getLiters() const;
    QString getLocation() const;
    int getMileage() const;
    double getPricePerLiter() const;
    void setId(int id);
    void setDate(const QDate &date);
    void setLiters(double liters);
    void setLocation(const QString &location);
    void setMileage(int mileage);
    void setPricePerLiter(double pricePerLiter);

    QString toString() const;
};

#endif /* TANK_H_ */
