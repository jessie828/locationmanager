#ifndef DATABASECONNECTION_H_
#define DATABASECONNECTION_H_

#include "location.h"
#include "trip.h"
#include <stdio.h>

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

class Database
{

public:
    static Database* getInstance();
    bool createConnection();
    bool insert(Trip *trip);
    bool insert(Location *location);
    ~Database();

protected:
    Database();

private:
    QSqlDatabase m_db;
    static Database* m_instance;

};

#endif /* DATABASECONNECTION_H_ */
