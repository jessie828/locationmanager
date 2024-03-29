#ifndef DATABASECONNECTION_H_
#define DATABASECONNECTION_H_

#include "location.h"
#include "trip.h"
#include "tank.h"
#include <stdio.h>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>

class Database
{

public:
    static const QString dateFormat;
    static Database* getInstance();
    bool createConnection();
    bool insert(Trip *trip);
    bool insert(Location *location);
    bool insert(Tank *tank);
    bool insert(const QString &fileName, const QString &fileType);
    bool TripImported(const QString &filename);
    int getLastTripId() const;
    QList<Trip> getTrips(const QDate &date);
    QList<Tank> getTanks(const QDate &date);
    QList<Trip> getTripsLocations(const QDate &date, int time);
    QList<Trip> getAllTrips();
    QList<Tank> getAllTanks();
    ~Database();

protected:
    Database();

private:
    QSqlDatabase m_db;
    static Database* m_instance;
    QDate findFirstDayOfWeek(const QDate &date);

};

#endif /* DATABASECONNECTION_H_ */
