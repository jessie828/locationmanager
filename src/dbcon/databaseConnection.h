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
    int getLastTripId() const;
    QList<Trip> getAllTrips(const QDate &date);
    QList<Tank> getAllTanks(const QDate &date);
    ~Database();

protected:
    Database();

private:
    QSqlDatabase m_db;
    static Database* m_instance;

};

#endif /* DATABASECONNECTION_H_ */
